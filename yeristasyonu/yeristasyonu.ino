#include <XBee.h>

XBee xbee = XBee();

XBeeResponse response = XBeeResponse();
unsigned long start = millis();

uint8_t payload[256];
char video[257];
char paket[178];
unsigned long start = millis();

boolean newData = false;

// SH + SL Address of receiving XBee
XBeeAddress64 addr64 = XBeeAddress64(0x0013a200, 0x403e0f30);
ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
ZBTxStatusResponse txStatus = ZBTxStatusResponse();

ZBRxResponse rx = ZBRxResponse();
ModemStatusResponse msr = ModemStatusResponse();

void setup(){
	Serial.begin(9600);
	Serial1.begin(9600);
  xbee.Setserial(Serial1);//değiştir
  

}

void loop(){
	XBee_Okuma();
	video_okuma();
	XBee_Gonder();

}


void XBee_Gonder(){
  xbee.send(zbTx);

  if (xbee.readPacket(500)) {
    Serial.println("Lokal XBee calisti.");
    if (xbee.getResponse().getApiId() == ZB_TX_STATUS_RESPONSE) {
      xbee.getResponse().getZBTxStatusResponse(txStatus);
      if (txStatus.getDeliveryStatus() == SUCCESS) {
        Serial.println("Paket basariyla gonderildi");
      } else {
        Serial.println("Alici Xbee paketi almadi, adresi ve konfigurasyonu kontrol et.");
      }
    }
  } else if (xbee.getResponse().isError()) {
    Serial.print("Paket okunurken hata. Hata kodu: ");  
    Serial.println(xbee.getResponse().getErrorCode());
  } else {
    Serial.println("Lokal XBee calismiyor, kablolamayi kontrol et");
  }
 
}

void XBee_Okuma(){
    Serial.println("xbee okuma basladi.");

    xbee.readPacket();
    
    
    
    if (xbee.getResponse().isAvailable()) {
      // got something
      Serial.println("Bir sey alindi.");
      if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
        // got a zb rx packet
        Serial.println("Paket alindi");
        // now fill our zb rx class
        xbee.getResponse().getZBRxResponse(rx);
            
        if (rx.getOption() == ZB_PACKET_ACKNOWLEDGED) {
            // the sender got an ACK
            Serial.println("Gonderici ACK'yi aldi");
        } else {
            // we got it (obviously) but sender didn't get an ACK
            Serial.println("Gonderici ACK'yi alamadi");
        }
        // set dataLed PWM to value of the first byte in the data
        Serial.println("getdata fonksiyonu cagirildi.");
        
        int a=0;
        while(a < 178){ 
        paket[a] = rx.getData(a);
        a++;
      }

        
        int i=0;
        while(i<a){ 
        Serial.print(paket[i]);
        i++;
      }

      
       
      } else if (xbee.getResponse().getApiId() == MODEM_STATUS_RESPONSE) {
        xbee.getResponse().getModemStatusResponse(msr);
        // the local XBee sends this response on certain events, like association/dissociation
        Serial.println("Donus yapildi");
        if (msr.getStatus() == ASSOCIATED) {
          Serial.println("assosicated");
        } else if (msr.getStatus() == DISASSOCIATED) {
          Serial.println("dissasociated");
        } else {
          Serial.println("hatali durum3"); 
        }
      } else {
        Serial.println("Hatali durum4");  
      }
    } else if (xbee.getResponse().isError()) {
      Serial.print("Paket okunurken hata olustu.  Hata kodu: ");  
      Serial.println(xbee.getResponse().getErrorCode());
    }   
   Serial.print('\n');
   String cikti = String(paket);
     
   return cikti;
        
}


void video_okuma(){
	static int indeks = 0;
	while(Serial.available() > 0{
	if(Serial.read() != '\n'){
	video[indeks] = Serial.read();
	indeks++;}
	if(Serial.read() == '\n'){
	return;
	}
	}
}

void String_to_Payload(){
  int i=0; 
  while(i< 256){
    payload[i]=video[i];
    i++;
  }
}
