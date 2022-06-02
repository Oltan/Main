void String_to_Payload(){
  int i=1;
  int str_len = telemetri_string.length();
  char char_array[str_len];
  telemetri_string.toCharArray(char_array,str_len); 
  while(str_len>i){
    payload[i-1]=char_array[i-1];
    i++;
  }

  
}
