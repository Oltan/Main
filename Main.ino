//GPS
#include <NMEAGPS.h>

static NMEAGPS  gps; // This parses received characters
static gps_fix  fix; // This contains all the parsed pieces

#include <GPSport.h>

//BMP180
#include <Adafruit_BMP085.h>
int ref_basinc = 101500;
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

static double pitch, roll, yaw;

//SD kart kutuphaneleri
#include <SD.h>
#include <SPI.h>

const int chipSelect = BUILTIN_SDCARD;

//XBee

#include <XBee.h>

XBee xbee = XBee();

unsigned long start = millis();

uint8_t payload[80];//Yollanacak byte dizisi

XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x403e0f30);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
ZBTxStatusResponse txStatus = ZBTxStatusResponse();


//Telemetri paket bilgileri

String telemetri_string = "";
String gps_saat_string = "";
String gps_konum_string = "";
String gps_yukseklik_string = "";
String takim_no = "1234";
int paket_sayisi = 0;

void setup()
{
  Serial.begin(9600);
  while (!Serial);

  while(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("BNO_055 baglantisini kontrol et.");
    
  }

  if (!bmp.begin()) {
    
  Serial.println("BMP180 baglantisi kontrol et.");
  while (!bmp.begin());
  }

  ref_basinc = bmp.readPressure();// Olunan yeri 0m kabul etmek için referans alinir.

  Serial.begin("SD kart baglantisi kuruluyor.");
  
  if (!SD.begin(chipSelect)) {
    Serial.println("Kart bozuk veya bagli degil.");
    while (!SD.begin(chipSelect));
  }
  Serial.println("Kart baglantisi yapildi.");

  Serial2.begin(9600);
  
  xbee.setSerial(Serial2);
  
  gpsPort.begin( 9600 );
}

//--------------------------

void loop()
{
  
  Basinc();

  
  Bnoloop();
  
  
  while (gps.available( gpsPort )) {
  GPSloop();
  }
  XBee_Okuma();
  Telemetri_olusturma();
  SD_kart();
  
}
