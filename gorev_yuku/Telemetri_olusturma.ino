void Telemetri_olusturma(String girdi){
    String irtifa_string;
    int irtifa_2;
    double z_hizi=0;
    double gerilim=11.6;
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
    telemetri_string += "<" + String(basinc) + ">,";
    for (int i = 0; i <= 7; i++)
    {
        telemetri_string += girdi[i];//basinc2yi stringe yazar
    }
    telemetri_string += ",";
    String yukseklik_string;
    sprintf_P(yukseklik_string,PSTR("%03d"),yukseklik);
    telemetri_string += "<" + yukseklik_string + ">,";
    for (int i = 8; i <= 12; i++)
    {
        telemetri_string += girdi[i];//yükseklik2 yazdırılır
    }
    for (int i = 9; i <= 11; i++)
    {
        irtifa_string += girdi[i];
    }
    irtifa_2 = irtifa_string.toInt();
    telemetri_string += ",";
    telemetri_string += "<" + String(0) + ">,";
    String inishizi;
    sprintf_P(inishizi,PSTR("%02d"),z_hizi); 
    telemetri_string += "<" + inishizi + ">,";
    telemetri_string += "<" + String(sicaklik) + ">,";
    telemetri_string += "<" + String(gerilim,1)+ ">,";
    telemetri_string += gps_konum_string + gps_yukseklik_string;
    for (int i = 12; i <= 41; i++)
    {
        telemetri_string += girdi[i];
    }
    telemetri_string += ",";
    telemetri_string += "<1>,";
    telemetri_string += "<" + String(pitch) + ">,<" + String(roll) + ">,<" + String(yaw) + ">,<" + "0" + ">,<" + "hayir" + ">";
    telemetri_string += "\0";
    
}
