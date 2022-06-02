void Telemetri_olusturma(String girdi){
    
    telemetri_string += "<";
    telemetri_string += takim_no;
    telemetri_string += ">";
    telemetri_string += ",";
    paket_sayisi++;
    telemetri_string += "<";
    telemetri_string += String(paket_sayisi);
    telemetri_string += ">";
    telemetri_string += ",";
    telemetri_string += gps_saat_string;
    
    telemetri_string += "<basinc>,<yukseklik>,<irtifafarki>,<inishizi>,<sicaklik>,<pilgerilim>,";
    telemetri_string += gps_konum_string + gps_yukseklik_string;
    telemetri_string += "<uydu_status>,";
    telemetri_string += "<" + String(pitch) + ">,<" + String(roll) + ">,<" + String(yaw) + ">,<" + "donussayisi" + ">,<" + "video=evet" + ">";
    telemetri_string += girdi;
    Serial.println(girdi);
    telemetri_string += "\n";
}
