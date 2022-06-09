#include <SD.h>
#include <SPI.h>
void create_payload() {
  

 char video_array[322725];
 char filename[] = "C:\\Users\\Alp Bora\\Desktop\\Callisto_video\\12080003.csv";

 File logfile = SD.open(filename,FILE_READ);
 size_t pos = 0;
 int c;
 while ((c = logfile.read()) != -1) {
  if ( c == ',' || c == '\n') {
    video_array[pos] = '\0';
    Serial.println(video_array);
    pos = 0;
  }

  else if (pos < 322725-1) {
    video_array[pos++] = c;
  }
 }

  int p = 0;

  while(p < 322725){
    payload[p]=video_array[p];
    p++;
  }
}
