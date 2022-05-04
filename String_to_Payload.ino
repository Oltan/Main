void String_to_Payload(){
  int i=1;
  while(telemetri_string.length()>i){
    payload[i-1]=telemetri_string[i-1];
    i++;
  }


  
}
