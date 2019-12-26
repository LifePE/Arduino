/*

네오픽셀LED를 이용한 한글 시계

열한다세네
두여섯일곱
여덟아홉(시)
정각이삼십
사오십오(분)


사용시에는 1분 또는 5분 간격으로 딜레이를 추가하고 allOff();

 */

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, 8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(5, 9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(5, 10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(5, 11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(5, 12, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip5.begin();
  strip.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show(); 
}

int hour[12][4]={{1,0},{0,1},{3,0},{4,0},{2,0,2,1},{1,1,2,1},{3,1,4,1},{1,1,1,2},{2,2,3,2},{0,0},{0,0,1,0},{0,0,0,1}};
int minute[12][6]={{0,3,1,3},{3,4},{2,4},{2,4,3,4},{2,3,4,3},{2,3,2,4,3,4},{3,3,4,3},{3,3,2,4,3,4},{0,4,2,4},{0,4,2,4,3,4},{1,4,2,4},{1,4,2,4,3,4}};

void allOff(){
  for(int x=0; x<=4; x++){
    strip.setPixelColor(x,0,0,0);
    strip2.setPixelColor(x,0,0,0);
    strip3.setPixelColor(x,0,0,0);
    strip4.setPixelColor(x,0,0,0);
    strip5.setPixelColor(x,0,0,0);
  }
}


void showLED(int x, int y){

  int cR=0;
  int cG=255;
  int cB=0;
  
  if(y==0){
    strip.setPixelColor(x,cR,cG,cB);
  }
  if(y==1){
    strip2.setPixelColor(x,cR,cG,cB);
  }
  if(y==2){
    strip3.setPixelColor(x,cR,cG,cB);
  }
  if(y==3){
    strip4.setPixelColor(x,cR,cG,cB);
  }
  if(y==4){
    strip5.setPixelColor(x,cR,cG,cB);
  }
  strip.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show();
}

void loop() {
  
  int Time=555;    //시간 (예를 들어 10시 1분일 때, 1001)
  int HOUR=(Time-(Time%100))/100;    //시
  int MINUTE=(Time%100-(Time%5))/5;    //분(5분 단위)

  //시
  showLED(hour[HOUR-1][0],hour[HOUR-1][1]);
  if(hour[HOUR-1][2]!=NULL){ 
    showLED(hour[HOUR-1][2],hour[HOUR-1][3]);
  }

  //글자 '시' (항상 켜져있음)
  showLED(4,2);

  //분
  showLED(minute[MINUTE][0],minute[MINUTE][1]);
  if(minute[MINUTE][2]!=NULL){ 
    showLED(minute[MINUTE][2],minute[MINUTE][3]);
  }
  if(minute[MINUTE][4]!=NULL){ 
    showLED(minute[MINUTE][4],minute[MINUTE][5]);
  }

  //글자 '분' (정각을 제외하고 항상 켜져있음)
  if(MINUTE!=0){
    showLED(4,4);
  }
  
}
