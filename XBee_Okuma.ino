String XBee_Okuma(){
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
        
        int a=1;
        while(a < 34){ 
        paket[a-1] = rx.getData(a-1);
        a++;
      }

        
        int i=1;
        while(i<a){ 
        Serial.print(paket[i-1]);
        i++;
      }
//        paket[0] = rx.getData(0);
//        paket[1] = rx.getData(1);
//        paket[2] = rx.getData(2);
//        paket[3] = rx.getData(3);
//        paket[4] = rx.getData(4);
//        paket[5] = rx.getData(5);
//        paket[6] = rx.getData(6);
//        paket[7] = rx.getData(7);
//        paket[8] = rx.getData(8);
//        paket[9] = rx.getData(9);
//        paket[10] = rx.getData(10);
//        paket[11] = rx.getData(11);
//        paket[12] = rx.getData(12);
//        paket[13] = rx.getData(13);
//        paket[14] = rx.getData(14);
//        paket[15] = rx.getData(15);
//        paket[16] = rx.getData(16);
//        paket[17] = rx.getData(17);
//        paket[18] = rx.getData(18);
//        paket[19] = rx.getData(19);
//        paket[20] = rx.getData(20);
//        paket[21] = rx.getData(21);
//        paket[22] = rx.getData(22);
//        paket[23] = rx.getData(23);
//        paket[24] = rx.getData(24);
//        paket[25] = rx.getData(25);
//        paket[26] = rx.getData(26);
//        paket[27] = rx.getData(27);
//        paket[28] = rx.getData(28);
//        paket[29] = rx.getData(29);
//        paket[30] = rx.getData(30);
//        paket[31] = rx.getData(31);
//        paket[32] = rx.getData(32);
//        paket[33] = rx.getData(33);
//        Serial.print(paket[0]);
//        Serial.print(paket[1]);
//        Serial.print(paket[2]);
//        Serial.print(paket[3]);
//        Serial.print(paket[4]);
//        Serial.print(paket[5]);
//        Serial.print(paket[6]);
//        Serial.print(paket[7]);
//        
//        Serial.println();
      
       
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
   Serial.println("xbee devam ediyor.");   
   
   String cikti = String(paket);
   Serial.println(cikti);
   Serial.println(paket);
   
   return cikti;
        
}
