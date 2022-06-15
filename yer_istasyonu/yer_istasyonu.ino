//SD kart kutuphaneleri
#include <SD.h>
#include <SPI.h>

const int chipSelect = BUILTIN_SDCARD;

unsigned long video_size;

//XBee
#include <XBee.h>
File videoFile;
XBee xbee = XBee();
XBeeResponse response = XBeeResponse();

ZBRxResponse rx = ZBRxResponse();
ModemStatusResponse msr = ModemStatusResponse();

uint8_t payload[240];//Yollanacak byte dizisi

XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x418fe9d8);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
ZBTxStatusResponse txStatus = ZBTxStatusResponse();

#define SERIAL2_TX_BUFFER_SIZE 512
#define SERIAL2_RX_BUFFER_SIZE 512



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600);
  xbee.setSerial(Serial2);
  //xbee.begin(Serial2);
  Serial.println("SD kart baglantisi kuruluyor.");
  
  if (!SD.begin(chipSelect)) {
    Serial.println("Kart bozuk veya bagli degil.");
    while (!SD.begin(chipSelect));
  }
  Serial.println("Kart baglantisi yapildi.");
  videoFile = SD.open("video.mp4", FILE_READ);
  video_size = videoFile.size();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (videoFile) {
    int i = 0;
    while(videoFile.available()){
        if (i>=240)
        {
            break;
        }
        payload[i] = videoFile.read();
        i++;
        Serial.print(payload[i]);
    } 
  } else {
    // if the file isn't open, pop up an error:
    Serial.println("video.mp4 acilamadi.");
  }
  Serial.println();
  XBee_Gonder();
  video_size = video_size - 240;
  if (video_size <= 0)
  {
    videoFile.close();
  }
  
  
}
