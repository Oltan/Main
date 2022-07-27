//========================================================================================================================//
//                                                 USER-SPECIFIED DEFINES                                                 //                                                                 
//========================================================================================================================//


//========================================================================================================================//

#include <SPI.h>      //SPI communication
#include <PWMServo.h> //commanding any extra actuators, installed with teensyduino installer

//Controller parameters (take note of defaults before modifying!): 
float i_limit = 25.0;     //Integrator saturation level, mostly for safety (default 25.0)
float maxRoll = 30.0;     //Max roll angle in degrees for angle mode (maximum 60 degrees), deg/sec for rate mode 
float maxPitch = 30.0;    //Max pitch angle in degrees for angle mode (maximum 60 degrees), deg/sec for rate mode
float maxYaw = 160.0;     //Max yaw rate in deg/sec

float Kp_roll_angle = 0.2;    //Roll P-gain - angle mode 
float Ki_roll_angle = 0.3;    //Roll I-gain - angle mode
float Kd_roll_angle = 0.05;   //Roll D-gain - angle mode (if using controlANGLE2(), set to 0.0)
float B_loop_roll = 0.9;      //Roll damping term for controlANGLE2(), lower is more damping (must be between 0 to 1)
float Kp_pitch_angle = 0.2;   //Pitch P-gain - angle mode
float Ki_pitch_angle = 0.3;   //Pitch I-gain - angle mode
float Kd_pitch_angle = 0.05;  //Pitch D-gain - angle mode (if using controlANGLE2(), set to 0.0)
float B_loop_pitch = 0.9;     //Pitch damping term for controlANGLE2(), lower is more damping (must be between 0 to 1)

float Kp_roll_rate = 0.15;    //Roll P-gain - rate mode
float Ki_roll_rate = 0.2;     //Roll I-gain - rate mode
float Kd_roll_rate = 0.0002;  //Roll D-gain - rate mode (be careful when increasing too high, motors will begin to overheat!)
float Kp_pitch_rate = 0.15;   //Pitch P-gain - rate mode
float Ki_pitch_rate = 0.2;    //Pitch I-gain - rate mode
float Kd_pitch_rate = 0.0002; //Pitch D-gain - rate mode (be careful when increasing too high, motors will begin to overheat!)

float Kp_yaw = 0.3;           //Yaw P-gain
float Ki_yaw = 0.05;          //Yaw I-gain
float Kd_yaw = 0.00015;       //Yaw D-gain (be careful when increasing too high, motors will begin to overheat!)
//Servo pinleri
const int servo1Pin = 6;
const int servo2Pin = 7;
const int servo3Pin = 8;
const int servo4Pin = 9;
const int servo5Pin = 10;
const int servo6Pin = 11;
const int servo7Pin = 12;

PWMServo servo1;  //create servo object to control a servo or ESC with PWM
PWMServo servo2;
PWMServo servo3;
PWMServo servo4;
PWMServo servo5;
PWMServo servo6;
PWMServo servo7;

//DECLARE GLOBAL VARIABLES

//General stuff
float dt;
unsigned long current_time, prev_time;
unsigned long print_counter, serial_counter;
unsigned long blink_counter, blink_delay;
bool blinkAlternate;

//GPS
#include <NMEAGPS.h>

static NMEAGPS  gps; // This parses received characters
static gps_fix  fix; // This contains all the parsed pieces

#include <GPSport.h>

int32_t gps_lon, gps_lat;
int alt;

//BMP180
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;

static float sicaklik;
static int32_t basinc, ref_basinc, yukseklik;

//bno_055
//
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
//
Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28);

double pitch, roll, yaw;

//SD kart kutuphaneleri
#include <SD.h>
#include <SPI.h>


const int chipSelect = BUILTIN_SDCARD;

//XBee

#include <XBee.h>

XBee xbee = XBee();
XBeeResponse response = XBeeResponse();

ZBRxResponse rx = ZBRxResponse();
ModemStatusResponse msr = ModemStatusResponse();

uint8_t payload[181];//Yollanacak byte dizisi

XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x418fe9d8);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
ZBTxStatusResponse txStatus = ZBTxStatusResponse();

#define SERIAL2_TX_BUFFER_SIZE 512
#define SERIAL2_RX_BUFFER_SIZE 512


//Telemetri paket bilgileri

String telemetri_string;
String gps_saat_string;
String gps_konum_string;
String XBee_paket;
String takim_no = "320421";
int paket_sayisi;
char paket[43];

void setup()
{
  Serial.begin(9600);
  Serial2.begin(115200);
  xbee.setSerial(Serial2);
  paket_sayisi = 1;
//  while (!Serial);
  
  pinMode(13, OUTPUT); 
  servo1.attach(servo1Pin, 900, 2100); //pin, min PWM value, max PWM value
  servo2.attach(servo2Pin, 900, 2100);
  servo3.attach(servo3Pin, 900, 2100);
  servo4.attach(servo4Pin, 900, 2100);
  servo5.attach(servo5Pin, 900, 2100);
  servo6.attach(servo6Pin, 900, 2100);
  servo7.attach(servo7Pin, 900, 2100);

  digitalWrite(13, HIGH);

  if (!bmp.begin()) {
    
  Serial.println("BMP180 baglantisi kontrol et.");
  while (!bmp.begin());
  }

  while(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("BNO_055 baglantisini kontrol et.");
    
  }
//
  

  ref_basinc = bmp.readPressure();// Olunan yeri 0m kabul etmek için referans alinir.

  Serial.println("SD kart baglantisi kuruluyor.");
  
  if (!SD.begin(chipSelect)) {
    Serial.println("Kart bozuk veya bagli degil.");
    while (!SD.begin(chipSelect));
  }
  Serial.println("Kart baglantisi yapildi.");
  
  gpsPort.begin( 9600 );
}

//--------------------------

void loop()
{
  prev_time = current_time;      
  current_time = micros();      
  dt = (current_time - prev_time)/1000000.0;

  loopBlink();

  controlANGLE2();

  controlMixer(); //mixes PID outputs to scaled actuator commands -- custom mixing assignments done here
  scaleCommands(); //scales motor commands to 125 to 250 range (oneshot125 protocol) and servo PWM commands to 0 to 180 (for servo library)


  basinc_hesap();
//
//  
  Bnoloop();
//  pidhesaplama();
  
  //while kaldırabilir aslında ama tam emin olamadım. while kaldırılıp test edilebilir.
  while (gps.available( gpsPort )) {
    fix = gps.read();
    gps_saat_string = GPS_saat();
    gps_konum_string = GPS_konum();
    //GPSloop();//
  }
  if(gps_saat_string == NULL && gps_konum_string == NULL){
    GPS_Bos();
  }


  XBee_paket = XBee_Okuma();
  Serial.println(XBee_paket);
  Telemetri_olusturma(XBee_paket);
  SD_Kart();
  String_to_Payload();
  XBee_Gonder();
  telemetri_string = "";
  gps_saat_string = "";
  gps_konum_string = ""; 
  loopRate(2000);

}

void controlANGLE2() {
  //DESCRIPTION: Computes control commands based on state error (angle) in cascaded scheme
  /*
   * Gives better performance than controlANGLE() but requires much more tuning. Not reccommended for first-time setup.
   * See the documentation for tuning this controller.
   */
  //Outer loop - PID on angle
  float roll_des_ol, pitch_des_ol;
  //Roll
  error_roll = roll_des - roll_IMU;
  integral_roll_ol = integral_roll_prev_ol + error_roll*dt;
  if (channel_1_pwm < 1060) {   //don't let integrator build if throttle is too low
    integral_roll_ol = 0;
  }
  integral_roll_ol = constrain(integral_roll_ol, -i_limit, i_limit); //saturate integrator to prevent unsafe buildup
  derivative_roll = (roll_IMU - roll_IMU_prev)/dt; 
  roll_des_ol = Kp_roll_angle*error_roll + Ki_roll_angle*integral_roll_ol - Kd_roll_angle*derivative_roll;

  //Pitch
  error_pitch = pitch_des - pitch_IMU;
  integral_pitch_ol = integral_pitch_prev_ol + error_pitch*dt;
  if (channel_1_pwm < 1060) {   //don't let integrator build if throttle is too low
    integral_pitch_ol = 0;
  }
  integral_pitch_ol = constrain(integral_pitch_ol, -i_limit, i_limit); //saturate integrator to prevent unsafe buildup
  derivative_pitch = (pitch_IMU - pitch_IMU_prev)/dt;
  pitch_des_ol = Kp_pitch_angle*error_pitch + Ki_pitch_angle*integral_pitch_ol - Kd_pitch_angle*derivative_pitch;

  //Apply loop gain, constrain, and LP filter for artificial damping
  float Kl = 30.0;
  roll_des_ol = Kl*roll_des_ol;
  pitch_des_ol = Kl*pitch_des_ol;
  roll_des_ol = constrain(roll_des_ol, -240.0, 240.0);
  pitch_des_ol = constrain(pitch_des_ol, -240.0, 240.0);
  roll_des_ol = (1.0 - B_loop_roll)*roll_des_prev + B_loop_roll*roll_des_ol;
  pitch_des_ol = (1.0 - B_loop_pitch)*pitch_des_prev + B_loop_pitch*pitch_des_ol;

  //Inner loop - PID on rate
  //Roll
  error_roll = roll_des_ol - GyroX;
  integral_roll_il = integral_roll_prev_il + error_roll*dt;
  if (channel_1_pwm < 1060) {   //don't let integrator build if throttle is too low
    integral_roll_il = 0;
  }
  integral_roll_il = constrain(integral_roll_il, -i_limit, i_limit); //saturate integrator to prevent unsafe buildup
  derivative_roll = (error_roll - error_roll_prev)/dt; 
  roll_PID = .01*(Kp_roll_rate*error_roll + Ki_roll_rate*integral_roll_il + Kd_roll_rate*derivative_roll); //scaled by .01 to bring within -1 to 1 range

  //Pitch
  error_pitch = pitch_des_ol - GyroY;
  integral_pitch_il = integral_pitch_prev_il + error_pitch*dt;
  if (channel_1_pwm < 1060) {   //don't let integrator build if throttle is too low
    integral_pitch_il = 0;
  }
  integral_pitch_il = constrain(integral_pitch_il, -i_limit, i_limit); //saturate integrator to prevent unsafe buildup
  derivative_pitch = (error_pitch - error_pitch_prev)/dt; 
  pitch_PID = .01*(Kp_pitch_rate*error_pitch + Ki_pitch_rate*integral_pitch_il + Kd_pitch_rate*derivative_pitch); //scaled by .01 to bring within -1 to 1 range
  
  //Yaw
  error_yaw = yaw_des - GyroZ;
  integral_yaw = integral_yaw_prev + error_yaw*dt;
  if (channel_1_pwm < 1060) {   //don't let integrator build if throttle is too low
    integral_yaw = 0;
  }
  integral_yaw = constrain(integral_yaw, -i_limit, i_limit); //saturate integrator to prevent unsafe buildup
  derivative_yaw = (error_yaw - error_yaw_prev)/dt; 
  yaw_PID = .01*(Kp_yaw*error_yaw + Ki_yaw*integral_yaw + Kd_yaw*derivative_yaw); //scaled by .01 to bring within -1 to 1 range
  
  //Update roll variables
  integral_roll_prev_ol = integral_roll_ol;
  integral_roll_prev_il = integral_roll_il;
  error_roll_prev = error_roll;
  roll_IMU_prev = roll_IMU;
  roll_des_prev = roll_des_ol;
  //Update pitch variables
  integral_pitch_prev_ol = integral_pitch_ol;
  integral_pitch_prev_il = integral_pitch_il;
  error_pitch_prev = error_pitch;
  pitch_IMU_prev = pitch_IMU;
  pitch_des_prev = pitch_des_ol;
  //Update yaw variables
  error_yaw_prev = error_yaw;
  integral_yaw_prev = integral_yaw;

}

void controlMixer() {
  //DESCRIPTION: Mixes scaled commands from PID controller to actuator outputs based on vehicle configuration
  /*
   * Takes roll_PID, pitch_PID, and yaw_PID computed from the PID controller and appropriately mixes them for the desired
   * vehicle configuration. For example on a quadcopter, the left two motors should have +roll_PID while the right two motors
   * should have -roll_PID. Front two should have -pitch_PID and the back two should have +pitch_PID etc... every motor has
   * normalized (0 to 1) thro_des command for throttle control. Can also apply direct unstabilized commands from the transmitter with 
   * roll_passthru, pitch_passthru, and yaw_passthu. mX_command_scaled and sX_command scaled variables are used in scaleCommands() 
   * in preparation to be sent to the motor ESCs and servos.
   */
  //Quad mixing
  //m1 = front left, m2 = front right, m3 = back right, m4 = back left
  m1_command_scaled = thro_des - pitch_PID + roll_PID + yaw_PID;
  m2_command_scaled = thro_des - pitch_PID - roll_PID - yaw_PID;
  m3_command_scaled = thro_des + pitch_PID - roll_PID + yaw_PID;
  m4_command_scaled = thro_des + pitch_PID + roll_PID - yaw_PID;
  m5_command_scaled = 0;
  m6_command_scaled = 0;

  //0.5 is centered servo, 0 is zero throttle if connecting to ESC for conventional PWM, 1 is max throttle
  s1_command_scaled = 0;
  s2_command_scaled = 0;
  s3_command_scaled = 0;
  s4_command_scaled = 0;
  s5_command_scaled = 0;
  s6_command_scaled = 0;
  s7_command_scaled = 0;

  //Example use of the linear fader for float type variables. Linearly interpolate between minimum and maximum values for Kp_pitch_rate variable based on state of channel 6:
  /*
  if (channel_6_pwm > 1500){ //go to max specified value in 5.5 seconds
    Kp_pitch_rate = floatFaderLinear(Kp_pitch_rate, 0.1, 0.3, 5.5, 1, 2000); //parameter, minimum value, maximum value, fadeTime (seconds), state (0 min or 1 max), loop frequency
  }
  if (channel_6_pwm < 1500) { //go to min specified value in 2.5 seconds
    Kp_pitch_rate = floatFaderLinear(Kp_pitch_rate, 0.1, 0.3, 2.5, 0, 2000); //parameter, minimum value, maximum value, fadeTime, state (0 min or 1 max), loop frequency
  }
  */
}