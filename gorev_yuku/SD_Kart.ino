void SD_Kart(){
  
    File dataFile  = SD.open("TMUY2022_320421_TLM.csv", FILE_WRITE);
    
    if (dataFile) {

    dataFile.println(telemetri_string);
   
//    dataFile.close();
    // print to the serial port too:
    //Serial.println(telemetri_string);
  } else {
    // if the file isn't open, pop up an error:
    Serial.println("Telemetri.csv acilamadi.");
  }
  }
