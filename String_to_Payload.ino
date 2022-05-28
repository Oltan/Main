void String_to_Payload(){
  int i=1;
  int str_len = telemetri_string.length();
  char char_array[200];
  telemetri_string.toCharArray(char_array,200); 
  while(200>i){
    payload[i-1]=char_array[i-1];
    i++;
  }

  
}
