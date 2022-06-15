void String_to_Payload(String telemetri_string){
  char char_array[44];
  telemetri_string.toCharArray(char_array,44); 
  for (int i = 0; i < 43; i++)
  {
    payload[i]=char_array[i];
  }
}
