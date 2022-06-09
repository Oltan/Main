void SD_Kart(){
    
    File dataFile = SD.open("video.csv", FILE_WRITE);
    
    if (dataFile) {

   // dataFile.println(video_string);
    dataFile.close();
    // print to the serial port too:
    //Serial.println(telemetri_string);
  } else {
    // if the file isn't open, pop up an error:
    Serial.println("Telemetri.csv acilamadi.");
  }
  }
