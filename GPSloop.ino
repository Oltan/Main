static void GPSloop()
{  
    fix = gps.read();
    // Display the local time
    
    gps_saat_string += ("<");
    gps_saat_string += takim_no;
    gps_saat_string += (">");
    gps_saat_string += ",";
    paket_sayisi++;
    gps_saat_string += ("<");
    gps_saat_string += String(paket_sayisi);
    gps_saat_string += (">");
    gps_saat_string += ",";
    if (fix.valid.time && fix.valid.date) {
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
    }

    if(fix.valid.location){
      gps_konum_string += "<";
      gps_konum_string += String(fix.latitude(),6);
      gps_konum_string += ">";
      gps_konum_string += ",";
      gps_konum_string += "<";
      gps_konum_string += String(fix.longitude(),6);
      gps_konum_string += ">";
      } 
   if (fix.valid.altitude){
      gps_yukseklik_string += ",";
      gps_yukseklik_string += "<";
      gps_yukseklik_string += String( fix.altitude(),6 );
      gps_yukseklik_string += ">";
    }

} // GPSloop
