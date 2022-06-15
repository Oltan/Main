void XBee_Gonder(){
  xbee.send(zbTx);

  if (xbee.readPacket(3000)) {
    Serial.println("Lokal XBee calisti.");
    if (xbee.getResponse().getApiId() == ZB_TX_STATUS_RESPONSE) {
      xbee.getResponse().getZBTxStatusResponse(txStatus);
      if (txStatus.getDeliveryStatus() == SUCCESS) {
        Serial.println("Paket basariyla gonderildi");
        Serial2.clear();
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
