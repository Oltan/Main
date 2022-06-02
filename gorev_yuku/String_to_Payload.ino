void String_to_Payload(){
  int i=1;
  char char_array[200];
  telemetri_string.toCharArray(char_array,200);
  char_array[199]= '\n'; 
  while(i< 200){
    payload[i-1]=char_array[i-1];
    i++;
  }

  
}
