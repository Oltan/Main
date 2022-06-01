static void GPSloop()
{  
    fix = gps.read();
    // Display the local time
    float alt;
    
    gps_saat_string += ("<");
    gps_saat_string += takim_no;
    gps_saat_string += (">");
    gps_saat_string += ",";
    paket_sayisi++;
    gps_saat_string += ("<");
    gps_saat_string += String(paket_sayisi);
    gps_saat_string += (">");
    gps_saat_string += ",";
      gps_saat_string += ("<");
      gps_saat_string += String(fix.dateTime.date);
      gps_saat_string += ("/");
      gps_saat_string += String(fix.dateTime.month);
      gps_saat_string += ("/");
      gps_saat_string += String(fix.dateTime.year);
      gps_saat_string += (",");
      gps_saat_string += String(fix.dateTime.hours+3);
      gps_saat_string += ("/");
      gps_saat_string += String(fix.dateTime.minutes);
      gps_saat_string += ("/");
      gps_saat_string += String(fix.dateTime.seconds);
      gps_saat_string += (">");
      gps_saat_string += ",";
    

   
      gps_konum_string += "<";
      gps_lat = fix.latitudeL();
      gps_konum_string += String(gps_lat,6);
      gps_konum_string += ">";
      gps_konum_string += ",";
      gps_konum_string += "<";
      gps_lon = fix.longitudeL(); 
      gps_konum_string += String(gps_lon,6);
      gps_konum_string += ">,";

      gps_yukseklik_string += "<";
      alt = fix.altitude();
      gps_yukseklik_string += String( alt );
      gps_yukseklik_string += ">,";
    

} // GPSloop
