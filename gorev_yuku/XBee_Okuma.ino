String XBee_Okuma(){
    Serial.println("xbee okuma basladi.");
    String cikti;
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


        for (int i = 0; i < 36; i++){
          paket[i]=rx.getData(i);
        }
        Serial.println(paket);
        cikti = String(paket);
        return cikti;
      
       
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
   Serial.println("hata paket okunamadı.");   
   cikti = "<00>,<00>";
   
   return cikti;
        
}
