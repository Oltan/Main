void basinc(){
  sicaklik = bmp.readTemperature();
  basinc = bmp.readPressure();
  yukseklik = bmp.readAltitude(ref_basinc);
  
  }
