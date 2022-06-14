void String_to_Payload(){
  int i=0;
  char char_array[184];
  telemetri_string.toCharArray(char_array,184);
  while(i< 184){
    if(char_array[i]=="\0"){
      break;
    }
    else{
      payload[i]=char_array[i];
      i++;
    }
  }
}
