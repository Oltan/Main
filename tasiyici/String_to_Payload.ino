void String_to_Payload(){
  char char_array[41];
  telemetri_string.toCharArray(char_array,43); 
  for (int i = 0; i < 41; i++)
  {
    payload[i]=char_array[i];
  }
  Serial.println(char_array);
}
