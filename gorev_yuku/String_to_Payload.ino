void String_to_Payload(){
  int i=0;
  char char_array[179];
  telemetri_string.toCharArray(char_array,179);
  while(i< 179){
    payload[i]=char_array[i];
    i++;
  }

}
