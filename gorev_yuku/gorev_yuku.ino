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

uint8_t payload[188];//Yollanacak byte dizisi

XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x418fe9d8);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
ZBTxStatusResponse txStatus = ZBTxStatusResponse();

#define SERIAL2_TX_BUFFER_SIZE 512
#define SERIAL2_RX_BUFFER_SIZE 512



//Servo ESC'ler icin
//#include<Servo.h>
//
//Servo ESC1,ESC2,ESC3,ESC4;




//Telemetri paket bilgileri

String telemetri_string;
String gps_saat_string;
String gps_konum_string;
String gps_yukseklik_string;
String XBee_paket;
String takim_no = "320421";
int paket_sayisi = 1;
char paket[43];

void setup()
{
  Serial.begin(9600);
  Serial2.begin(9600);
  xbee.setSerial(Serial2);
  while (!Serial);

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
  
  basinc_hesap();
//
//  
  Bnoloop();
//  pidhesaplama();
  
  //while kaldırabilir aslında ama tam emin olamadım. while kaldırılıp test edilebilir.
  if (gps.available( gpsPort )) {
    GPSloop();//
  }
  else{
    GPS_Bos();
  }

  XBee_paket = XBee_Okuma();
  Serial.println(XBee_paket);
  Telemetri_olusturma(XBee_paket);
  SD_Kart();
  String_to_Payload();
  XBee_Gonder();
  
}
