String Telemetri(String gps_string){
    int basinc; 
    String telemetri_string = "";
    basinc = bmp.readPressure();
    yukseklik = bmp.readAltitude(ref_basinc);
    telemetri_string += "<";// + String(basinc) + ">";
    char basinc_string[6];
    sprintf_P(basinc_string,PSTR("%06d"),basinc);
    telemetri_string += basinc_string;
    telemetri_string += ">";
    telemetri_string += "<";// + String(yukseklik) + ">";
    char yukseklik_string[3];
    sprintf_P(yukseklik_string,PSTR("%03d"),yukseklik);
    telemetri_string += yukseklik_string;
    telemetri_string += ">";
    telemetri_string += gps_string;
    
    Serial.println(telemetri_string);
    return telemetri_string;
}
