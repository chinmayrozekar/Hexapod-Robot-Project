#include "SSC32.h"
SSC32 mySSC32;
bool mybool = true;
int channels[] = {0,1,2,3,4,5,16,17,18,19,20,21};
int homeFrame[] = {1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500};

int home1[] = {1900, 1100, 1300, 1900, 1900, 1100, 1900, 1100, 1300, 1900, 1900, 1100};
int home2[] = {1300, 1100, 1900, 1900, 1300, 1100, 1300, 1100, 1900, 1900, 1300, 1100};
int home3[] = {1300, 1900, 1900, 1100, 1300, 1900, 1300, 1900, 1900, 1100, 1300, 1900};
int home4[] = {1900, 1900, 1300, 1100, 1900, 1900, 1900, 1900, 1300, 1100, 1900, 1900};

void setup() {                  
  mySSC32.begin(9600);
  mySSC32.enableServos(channels);
  mySSC32.setFrame(homeFrame);
  pinMode(13,OUTPUT);
}

void loop() {

  //Serial.println(micros());
  
     mySSC32.setFrame(home1);
   delay(500);
     mySSC32.setFrame(home2);
   delay(500);
     mySSC32.setFrame(home3);
   delay(500);
     mySSC32.setFrame(home4);
   delay(500);
         
}   