void String_to_Payload(){
  int i=0;
  char char_array[181];
  telemetri_string.toCharArray(char_array,181);
  while(i< 181){
//    if(char_array[i]=='\0'){
//      break;
//    }
//    else{
      payload[i]=char_array[i];
      i++;
//    }
  }
}
