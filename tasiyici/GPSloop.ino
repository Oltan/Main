static String GPSloop()
{  
  String gps_string;
  fix = gps.read();
      if (fix.valid.location)
      {
            int alt;
            float lat = 0; float longt = 0;
            gps_string += "<";
            char lat_string[9];
            lat = fix.latitude();
            sprintf_P(lat_string,PSTR("%09.6f"),lat);
            gps_string += lat_string;
            gps_string += ">";
            gps_string += ">";
            gps_string += "<";
            char longt_string[9];
            longt = fix.longitude();
            sprintf_P(longt_string,PSTR("%09.6f"),longt);
            gps_string += longt_string;
            gps_string += ">,";
            gps_string += "<";
            char altit_string[4];
            alt = fix.altitude();
            sprintf_P(altit_string,PSTR("%04d"),alt);
            gps_string += altit_string;
            gps_string += ">,";
            return gps_string;
      }
     
    
} // GPSloop

static String GPS_Bos(){
      String gps_string;
//    float lat = 0; float longt = 0; double altit = 0;
//    gps_konum_string += "<";
//    //gps_konum_string += String(lat,6);
//    char lat_string[9];
//    sprintf_P(lat_string,PSTR("%09.6d"),lat);
//    gps_konum_string += lat_string;
//    gps_konum_string += ">,";
//    gps_konum_string += "<";
//   //gps_konum_string += String(longt,6);
//    char longt_string[9];
//    sprintf_P(longt_string,PSTR("%09.6d"),longt);
//    gps_konum_string += longt_string;
//    gps_konum_string += ">,";
//    
//   
//    gps_string += "<";
//    int alt = 0;
//    char altit_string[4];
//    sprintf_P(altit_string,PSTR("%04d"),alt);
//    gps_yukseklik_string += altit_string;
//    gps_yukseklik_string += ">,";

      gps_string += "<00.000000>,<00.000000>,<0000>";
      return gps_string;
}
