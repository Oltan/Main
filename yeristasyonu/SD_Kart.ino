void SD_Kart(){
    
    videoFile = SD.open("video.mp4", FILE_READ);
    
    if (videoFile) {

    video_size = videoFile.size();
    while(videoFile.available()){
        if (i>=254)
        {
            break;
        }
        payload[i] = videoFile();
    }
    
  } else {
    // if the file isn't open, pop up an error:
    Serial.println("video.mp4 acilamadi.");
  }
  }
