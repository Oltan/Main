static void GPSloop()
{  
    fix = gps.read();
    // Display the local time
    String dataString = "";
    if (fix.valid.time && fix.valid.date) {
      dataString += ("<");
      dataString += String(fix.dateTime.date);
      dataString += ("/");
      dataString += String(fix.dateTime.month);
      dataString += ("/");
      dataString += String(fix.dateTime.year);
      dataString += (",");
      dataString += String(fix.dateTime.hours+3);
      dataString += ("/");
      dataString += String(fix.dateTime.minutes);
      dataString += ("/");
      dataString += String(fix.dateTime.seconds);
      dataString += (">");
      dataString += ",";
    }
    DEBUG_PORT.print(dataString);
    DEBUG_PORT.println();
  

} // GPSloop
