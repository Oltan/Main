void Telemetri(){
    
    int basinc = bmp.readPressure();
    int yukseklik = bmp.readAltitude(ref_basinc);
    telemetri_string += "<" + String(basinc) + ">,";
    telemetri_string += "<" + String(yukseklik) + ">,";
    telemetri_string += gps_yukseklik_string;
    telemetri_string += gps_konum_string;
    
    
}
