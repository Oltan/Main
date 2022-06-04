void String_to_Payload(){
  char char_array[36];
  telemetri_string.toCharArray(char_array,36); 
  for (int i = 0; i < 36; i++)
  {
    payload[i-1]=char_array[i-1];
    i++;
  }
  
    
  

  
}
