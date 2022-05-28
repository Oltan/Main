String XBee_Okuma(){
//  xbee.readPacket();
//    
//    if (xbee.getResponse().isAvailable()) {
//      // got something
//      
//      if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
//        // got a zb rx packet
//        Serial.println("Paket alindi");
//        // now fill our zb rx class
//        xbee.getResponse().getZBRxResponse(rx);
//            
//        if (rx.getOption() == ZB_PACKET_ACKNOWLEDGED) {
//            // the sender got an ACK
//            Serial.println("Gonderici ACK'yi aldi");
//        } else {
//            // we got it (obviously) but sender didn't get an ACK
//            Serial.println("Gonderici ACK'yi alamaadi");
//        }
//        // set dataLed PWM to value of the first byte in the data
//        // analogWrite(dataLed, rx.getData(0));
//        char paket[rx.getDataLength()+1];
//        int i=1;
//        while(i<rx.getDataLength()){
//          paket[i-1]=rx.getData(i-1);
//          i++;
//        }
//        
//
//       
//      } else if (xbee.getResponse().getApiId() == MODEM_STATUS_RESPONSE) {
//        xbee.getResponse().getModemStatusResponse(msr);
//        // the local XBee sends this response on certain events, like association/dissociation
//        
//        if (msr.getStatus() == ASSOCIATED) {
//          Serial.println("Donus yapildi");
//          flashLed(statusLed, 10, 10);
//        } else if (msr.getStatus() == DISASSOCIATED) {
//          // this is awful.. flash led to show our discontent
//          Serial.println("Hatali paket1");
//        } else {
//          // another status
//          Serial.println("Hatali paket2");
//        }
//      } else {
//        Serial.println("Hatali paket3");   
//      }
//    } else if (xbee.getResponse().isError()) {
//      Serial.print("Paket okunurken hata olustu.  Hata kodu: ");  
//      Serial.println(xbee.getResponse().getErrorCode());
//    }
//
//   String cikti = String(paket);
//   return cikti;

    xbee.readPacket();
    
    if (xbee.getResponse().isAvailable()) {
      // got something
      //Serial.println("Bir sey alindi.");
      if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
        // got a zb rx packet
        //Serial.println("Paket alindi");
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
        
        int a;
        while(a<80){ 
        paket[i-1] = rx.getData(i-1);
        a++;
      }

        
        int i;
        while(i<80){ 
        Serial.print(paket[i-1]);
        i++;
      }
        Serial.println();
      
       
      } else if (xbee.getResponse().getApiId() == MODEM_STATUS_RESPONSE) {
        xbee.getResponse().getModemStatusResponse(msr);
        // the local XBee sends this response on certain events, like association/dissociation
        Serial.println("Donus yapildi");
        if (msr.getStatus() == ASSOCIATED) {
          Serial.println("Hatali paket1");
        } else if (msr.getStatus() == DISASSOCIATED) {
          Serial.println("Hatali paket1");
        } else {
          Serial.println("Hatali paket2"); 
        }
      } else {
        Serial.println("Hatali paket3");  
      }
    } else if (xbee.getResponse().isError()) {
      Serial.print("Paket okunurken hata olustu.  Hata kodu: ");  
      Serial.println(xbee.getResponse().getErrorCode());
    }
      
   String cikti = String(paket);
   return cikti;
        
}
