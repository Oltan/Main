static void GPSloop()
{  
    fix = gps.read();
    
    if(fix.valid.location){
      gps_konum_string += "<";
      gps_konum_string += String(fix.latitude(),6);
      gps_konum_string += ">";
      gps_konum_string += ",";
      gps_konum_string += "<";
      gps_konum_string += String(fix.longitude(),6);
      gps_konum_string += ">,";
      } 
   if (fix.valid.altitude){
      gps_yukseklik_string += "<";
      gps_yukseklik_string += String( fix.altitude(),6);
      gps_yukseklik_string += ">";
    }

} // GPSloop
