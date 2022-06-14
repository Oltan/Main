//////GPS
#include <NMEAGPS.h>
////
static NMEAGPS  gps; // This parses received characters
static gps_fix  fix; // This contains all the parsed pieces
////
#include <GPSport.h>
////
int32_t gps_lon, gps_lat;
//
#include <XBee.h>

XBee xbee = XBee();

uint8_t payload[41];

// SH + SL Address of receiving XBee
XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x403e0f30);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
ZBTxStatusResponse txStatus = ZBTxStatusResponse();

#include <Adafruit_BMP085.h>
int ref_basinc = 101500;
Adafruit_BMP085 bmp;

String gps_konum_string;
String gps_yukseklik_string;
String XBee_paket;
String telemetri_string;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if (!bmp.begin()) {
    
  Serial.println("BMP180 baglantisi kontrol et.");
  while (!bmp.begin());
  }

  ref_basinc = bmp.readPressure();// Olunan yeri 0m kabul etmek için referans alinir.


  Serial2.begin(9600);
  xbee.setSerial(Serial2);
  gpsPort.begin( 9600 );
}

void loop() {
  
  if (gps.available( gpsPort )) {
    GPSloop();
  }
  else{
    GPS_Bos();
  }
  Telemetri();
  String_to_Payload();
  XBee_Gonder();
}
