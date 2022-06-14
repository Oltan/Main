static void GPSloop()
{  
    fix = gps.read();
    int alt;
    
    gps_konum_string += "<";
    gps_konum_string += String(fix.latitude(),6);
    gps_konum_string += ">";
    gps_konum_string += "<";
    gps_konum_string += String(fix.longitude(),6);
    gps_konum_string += ">";
    
   
    gps_yukseklik_string += "<";
    char altit_string[4];
    alt = fix.altitude();
    sprintf_P(altit_string,PSTR("%03d"),alt);
    gps_yukseklik_string += altit_string;
    gps_yukseklik_string += ">,";
  

} // GPSloop

static void GPS_Bos(){

    float lat = 0; float longt = 0; double altit = 0;
    gps_konum_string += "<";
    gps_konum_string += String(lat,6);
    gps_konum_string += ">";
    gps_konum_string += "<";
    gps_konum_string += String(longt,6);
    gps_konum_string += ">";
    
   
    gps_yukseklik_string += "<";
    int alt = 0;
    char altit_string[4];
    sprintf_P(altit_string,PSTR("%03d"),alt);
    gps_yukseklik_string += altit_string;
    gps_yukseklik_string += ">,";

}
