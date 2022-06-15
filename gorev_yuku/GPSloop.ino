static void GPSloop()
{  
    fix = gps.read();
    uint8_t gun, ay, yil, saat, dakika, saniye;
    // Display the local time
    gps_saat_string += ("<");
    char gun_string[2];
    gun = fix.dateTime.date;
    sprintf_P(gun_string,PSTR("%02d"),gun);
    gps_saat_string += gun_string;
    gps_saat_string += ("/");
    //gps_saat_string += String(fix.dateTime.month);
    ay = fix.dateTime.month;
    sprintf_P(gun_string,PSTR("%02d"),ay);
    gps_saat_string += gun_string;
    gps_saat_string += ("/");
    //gps_saat_string += String(fix.dateTime.year);
    yil = fix.dateTime.year;
    sprintf_P(gun_string,PSTR("%02d"),yil);
    gps_saat_string += gun_string;
    gps_saat_string += (",");
    //gps_saat_string += String(fix.dateTime.hours+3);
    saat = fix.dateTime.hours+3;
    sprintf_P(gun_string,PSTR("%02d"),saat);
    gps_saat_string += gun_string;
    gps_saat_string += ("/");
    //gps_saat_string += String(fix.dateTime.minutes);
    dakika = fix.dateTime.minutes;
    sprintf_P(gun_string,PSTR("%02d"),dakika);
    gps_saat_string += gun_string;
    gps_saat_string += ("/");
    //gps_saat_string += String(fix.dateTime.seconds);
    saniye = fix.dateTime.seconds;
    sprintf_P(gun_string,PSTR("%02d"),saniye);
    gps_saat_string += gun_string;
    gps_saat_string += (">");
    gps_saat_string += ",";

   
    gps_konum_string += "<";
    gps_lat = fix.latitudeL();
    char lat_string[9];
    sprintf_P(lat_string,PSTR("%09.6ld"),gps_lat);
    gps_konum_string += lat_string;
    //gps_konum_string += String(gps_lat,6);
    gps_konum_string += ">";
    gps_konum_string += ",";
    gps_konum_string += "<";
    gps_lon = fix.longitudeL();
    char longt_string[9];
    sprintf_P(longt_string,PSTR("%09.6ld"),gps_lon);
    gps_konum_string += longt_string; 
    //gps_konum_string += String(gps_lon,6);
    gps_konum_string += ">,";

    gps_yukseklik_string += "<";
    alt = fix.altitude();
    char altit_string[4];
    sprintf_P(altit_string,PSTR("%03d"),alt);
    gps_yukseklik_string += altit_string;
    gps_yukseklik_string += ">,";
    /*if (fix.valid.altitude && fix.valid.date && fix.valid.time) {//BU kodu daha denemedim, kütüphane sayfasından buldum.
      dt = (clock_t) fix.dateTime - (clock_t) fix.dateTime;
      dz = fix_copy.alt.whole - last_alt;  // meters
      vz = dz / dt;                         // meters per second vertical velocity
    }*/
    

} // GPSloop

static void GPS_Bos(){

//    gps_saat_string += ("<");
//    gps_saat_string += String(0);
//    gps_saat_string += ("/");
//    gps_saat_string += String(0);
//    gps_saat_string += ("/");
//    gps_saat_string += String(0);
//    gps_saat_string += (",");
//    gps_saat_string += String(0);
//    gps_saat_string += ("/");
//    gps_saat_string += String(0);
//    gps_saat_string += ("/");
//    gps_saat_string += String(0);
//    gps_saat_string += (">");
//    gps_saat_string += ",";
    gps_saat_string += "<00/00/00,00/00/00>,";
    gps_konum_string += "<00.000000>,<00.000000>";
    gps_yukseklik_string += "<0000>";
   
//    gps_konum_string += "<";
//    gps_lat = 0;
//    gps_konum_string += String(gps_lat,6);
//    gps_konum_string += ">";
//    gps_konum_string += ",";
//    gps_konum_string += "<";
//    gps_lon = 0; 
//    gps_konum_string += String(gps_lon,6);
//    gps_konum_string += ">,";
//
//    gps_yukseklik_string += "<";
//    alt = 0;
//    char altit_string[4];
//    sprintf_P(altit_string,PSTR("%03d"),alt);
//    gps_yukseklik_string += altit_string;
//    gps_yukseklik_string += ">,";



}
