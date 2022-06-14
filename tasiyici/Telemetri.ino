void Telemetri(){
    int basinc; 
    basinc = bmp.readPressure();
    yukseklik = bmp.readAltitude(ref_basinc);
    telemetri_string += "<" + String(basinc) + ">";
    telemetri_string += "<" + String(yukseklik) + ">";
    telemetri_string += gps_konum_string;
    telemetri_string += gps_yukseklik_string;
    
    Serial.println(telemetri_string);
    
}
