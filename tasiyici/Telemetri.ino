void Telemetri(){
    int basinc; 
    basinc = bmp.readPressure();
    int yukseklik;
    String yukseklik_string, basinc_string;
    yukseklik = bmp.readAltitude(ref_basinc);
    sprintf_P(basinc_string,PSTR("%06d"),basinc);
    telemetri_string += "<" + basinc_string + ">";
    sprintf_P(yukseklik_string,PSTR("%03d"),yukseklik);
    telemetri_string += "<" + yukseklik_string + ">";
    telemetri_string += gps_konum_string;
    telemetri_string += gps_yukseklik_string;
    
    Serial.println(telemetri_string);
    
}
