void SD_Kart(){
    
    File telemetriFile = SD.open("telemetri.csv", FILE_WRITE);
    
    if (dataFile) {

    telemetriFile.println(telemetriString);
    telemetriFile.close();
    // print to the serial port too:
    Serial.println(telemetriString);
  } else {
    // if the file isn't open, pop up an error:
    Serial.println("Telemetri.csv acilamadi.");
  }
  }
