void Telemetri_olusturma(String girdi){
    string irtifa_string[4];
    int irtifa_2;
    double z_hizi=0;
    telemetri_string += "<";
    telemetri_string += takim_no;
    telemetri_string += ">";
    telemetri_string += ",";
    telemetri_string += "<";
    telemetri_string += String(paket_sayisi);paket_sayisi++;
    telemetri_string += ">";
    telemetri_string += ",";
    telemetri_string += gps_saat_string;
 //   telemetri_string += "<basinc>,<yukseklik>,<irtifafarki>,<inishizi>,<sicaklik>,<pilgerilim>,";
    telemetri_string += "<" + String(basinc) + ">,<";
    for (int i = 0; i <= 7; i++)
    {
        telemetri_string += girdi[i];//basinc2yi stringe yazar
    }
    telemetri_string += ",";
    telemetri_string += gps_yukseklik_string;
    for (int i = 8; i <= 12; i++)
    {
        telemetri_string += girdi[i];//yükseklik2 yazdırılır
    }
    for (int i = 9; i <= 11; i++)
    {
        irtifa_string += girdi[i];
    }
    irtifa_2 = irtifa_string.toint();
    telemetri_string += ",<" + String(alt-irtifa_2) + ">"; 
    telemetri_string += ",<" + String(z_hizi, 2) + ">";
    telemetri_string += gps_konum_string + gps_yukseklik_string;
    telemetri_string += "<uydu_status>,";
    telemetri_string += "<" + String(pitch) + ">,<" + String(roll) + ">,<" + String(yaw) + ">,<" + "donussayisi" + ">,<" + "video=evet" + ">";
    telemetri_string += girdi;
    Serial.println(girdi);
    telemetri_string += "\n";
}