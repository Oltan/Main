static void basinc_hesap(){
  sicaklik = bmp.readTemperature();
  basinc = bmp.readPressure();
  yukseklik = bmp.readAltitude(ref_basinc);
  
  }
