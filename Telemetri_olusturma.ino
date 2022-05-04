void Telemetri_olusturma(){
    
    telemetri_string += ("<");
    telemetri_string += takim_no;
    telemetri_string += (">");
    telemetri_string += ",";
    paket_sayisi++;
    telemetri_string += ("<");
    telemetri_string += String(paket_sayisi);
    telemetri_string += (">");
    telemetri_string += ",";
    telemetri_string += gps_saat_string;
    
    telemetri_string += ("<")+ String(basinc) + (">,<") + + ("Basinc2") + (">,<")+ String(yukseklik) + (">,<") + ("Yukseklik2") + (">,<") + ("irtifafarki") + (">,<") + ("inishizi") + (">,<") + String(sicaklik) + (">,<") + ("pilgerilim") + (">,");
    telemetri_string += gps_konum_string + gps_yukseklik_string + ("<latitude2>,<longitude2>,<altitude2>,");
    telemetri_string += ("<uydu_status>,");
    telemetri_string += ("<") + String(pitch) + (">,<") + String(roll) + (">,<") + String(yaw) + (">,<") + ("donussayisi") + (">,<") + ("video=evet") + (">");
    
}
