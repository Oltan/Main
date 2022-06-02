void Telemetri(){
    
    int sicaklik = bmp.readTemperature();
    int basinc = bmp.readPressure();
    int yukseklik = bmp.readAltitude(ref_basinc);
    telemetri_string += "<" + String(basinc) + ">,";
    telemetri_string += gps_yukseklik_string;
    telemetri_string += gps_konum_string;
    
    
}
