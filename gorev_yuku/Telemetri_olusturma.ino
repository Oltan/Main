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
    telemetri_string += String(paket_sayisi);
    paket_sayisi++;
    telemetri_string += ">";
    telemetri_string += ",";
    telemetri_string += gps_saat_string;
 //   telemetri_string += "<basinc>,<yukseklik>,<irtifafarki>,<inishizi>,<sicaklik>,<pilgerilim>,";
    telemetri_string += "<";// + String(basinc) + ">";
    char basinc_string[6];
    sprintf_P(basinc_string,PSTR("%06d"),basinc);
    telemetri_string += basinc_string;
    telemetri_string += ">,";
    for (int i = 0; i <= 7; i++)
    {
        telemetri_string += girdi[i];//basinc2yi stringe yazar
    }
    telemetri_string += ",";
    telemetri_string += "<";// + String(yukseklik) + ">";
    char yukseklik_string[3];
    sprintf_P(yukseklik_string,PSTR("%03d"),yukseklik);
    telemetri_string += yukseklik_string;
    telemetri_string += ">,";
    for (int i = 8; i <= 12; i++)
    {
        telemetri_string += girdi[i];//yükseklik2 yazdırılır
    }
    for (int i = 9; i <= 11; i++)
    {
        irtifa_string += girdi[i];
    }
    irtifa_2 = irtifa_string.toInt();
    telemetri_string += ",<" + String(alt-irtifa_2) + ">"; 
    telemetri_string += ",<" + String(z_hizi, 2) + ">";
    telemetri_string += ",<" + String(sicaklik) + ">";
    telemetri_string += ",<" + String(gerilim,1)+ ">,";
    telemetri_string += gps_konum_string;
    for (int i = 13; i < 43; i++)
    {
        telemetri_string += girdi[i];
    }
    telemetri_string += ",<1>,";
    telemetri_string += "<";
    char bno_string[3];
    sprintf_P(bno_string,PSTR("%03.0f"),pitch);
    telemetri_string += bno_string;
    telemetri_string += ">,";
    telemetri_string += "<";
    sprintf_P(bno_string,PSTR("%03.0f"),roll);
    telemetri_string += bno_string;
    telemetri_string += ">,";
    telemetri_string += "<";
    sprintf_P(bno_string,PSTR("%03.0f"),roll);
    telemetri_string += bno_string;
    telemetri_string += ">,<hayir>";
    //telemetri_string += "<" + String(pitch) + ">,<" + String(roll) + ">,<" + String(yaw) + ">,<" + "0" + ">,<" + "hayir" + ">";
}
