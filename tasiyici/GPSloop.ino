static void GPSloop()
{  
    fix = gps.read();
    
    
    gps_konum_string += "<";
    gps_konum_string += String(fix.latitude(),6);
    gps_konum_string += ">";
    gps_konum_string += ",";
    gps_konum_string += "<";
    gps_konum_string += String(fix.longitude(),6);
    gps_konum_string += ">,";
    
   
    gps_yukseklik_string += "<";
    gps_yukseklik_string += String(fix.altitude());
    gps_yukseklik_string += ">";
  

} // GPSloop

static void GPS_Bos(){

    float lat = 0; float longt = 0; double altit = 0;
    gps_konum_string += "<";
    gps_konum_string += String(lat,6);
    gps_konum_string += ">";
    gps_konum_string += ",";
    gps_konum_string += "<";
    gps_konum_string += String(longt,6);
    gps_konum_string += ">,";
    
   
    gps_yukseklik_string += "<";
    String altit_string;
    sprintf(altit_string,"%03d",altit);
    gps_yukseklik_string += altit_string;
    gps_yukseklik_string += ">";

}