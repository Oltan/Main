//SD kart kutuphaneleri
#include <SD.h>
#include <SPI.h>

const int chipSelect = BUILTIN_SDCARD;

//XBee

#include <XBee.h>

XBee xbee = XBee();
unsigned long start = millis();

uint8_t payload[200];//Yollanacak byte dizisi

XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x40de14d6);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
ZBTxStatusResponse txStatus = ZBTxStatusResponse();


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600);
  xbee.setSerial(Serial2);
  //xbee.begin(Serial2);
  while (!Serial);
  Serial.println("SD kart baglantisi kuruluyor.");
  
  if (!SD.begin(chipSelect)) {
    Serial.println("Kart bozuk veya bagli degil.");
    while (!SD.begin(chipSelect));
  }
  Serial.println("Kart baglantisi yapildi.");
}

void loop() {
  // put your main code here, to run repeatedly:
  SD_Kart();
  create_payload();
  XBee_Gonder();
}
