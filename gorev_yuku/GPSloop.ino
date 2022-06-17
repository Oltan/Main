static String GPS_saat()
{  
    //fix = gps.read();
    String saat_string;
    uint8_t gun, ay, yil, saat, dakika, saniye;
    // Display the local time
    if (fix.valid.time && fix.valid.date)
    {
        saat_string += ("<");
        char gun_string[2];
        gun = fix.dateTime.date;
        sprintf_P(gun_string,PSTR("%02d"),gun);
        saat_string += gun_string;
        saat_string += ("/");
        //saat_string += String(fix.dateTime.month);
        ay = fix.dateTime.month;
        sprintf_P(gun_string,PSTR("%02d"),ay);
        saat_string += gun_string;
        saat_string += ("/");
        //saat_string += String(fix.dateTime.year);
        yil = fix.dateTime.year;
        sprintf_P(gun_string,PSTR("%02d"),yil);
        saat_string += gun_string;
        saat_string += (",");
        //saat_string += String(fix.dateTime.hours+3);
        saat = fix.dateTime.hours+3;
        sprintf_P(gun_string,PSTR("%02d"),saat);
        saat_string += gun_string;
        saat_string += ("/");
        //saat_string += String(fix.dateTime.minutes);
        dakika = fix.dateTime.minutes;
        sprintf_P(gun_string,PSTR("%02d"),dakika);
        saat_string += gun_string;
        saat_string += ("/");
        //saat_string += String(fix.dateTime.seconds);
        saniye = fix.dateTime.seconds;
        sprintf_P(gun_string,PSTR("%02d"),saniye);
        saat_string += gun_string;
        saat_string += (">");
        saat_string += ",";
        return saat_string;
    }
   
    
}

static String GPS_konum()
{   
    if (fix.valid.location)
    {
        String konum_string;
        konum_string += "<";
        gps_lat = fix.latitudeL();
        char lat_string[9];
        sprintf_P(lat_string,PSTR("%09.6ld"),gps_lat);
        konum_string += lat_string;
        //konum_string += String(gps_lat,6);
        konum_string += ">";
        konum_string += ",";
        konum_string += "<";
        gps_lon = fix.longitudeL();
        char longt_string[9];
        sprintf_P(longt_string,PSTR("%09.6ld"),gps_lon);
        konum_string += longt_string; 
        //konum_string += String(gps_lon,6);
        konum_string += ">,";

        konum_string += "<";
        alt = fix.altitude();
        char altit_string[4];
        sprintf_P(altit_string,PSTR("%04d"),alt);
        konum_string += altit_string;
        konum_string += ">,";
        /*if (fix.valid.altitude && fix.valid.date && fix.valid.time) {//BU kodu daha denemedim, kütüphane sayfasından buldum.
        dt = (clock_t) fix.dateTime - (clock_t) fix.dateTime;
        dz = fix_copy.alt.whole - last_alt;  // meters
        vz = dz / dt;                         // meters per second vertical velocity
        }*/
        return konum_string;
    }
    
    
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
    gps_konum_string += "<00.000000>,<00.000000>,<0000>";
   
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
