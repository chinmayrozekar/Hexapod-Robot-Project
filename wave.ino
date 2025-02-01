#include "SSC32.h"
SSC32 mySSC32;
bool mybool = true;
int channels[] = {0,1,2,3,4,5,16,17,18,19,20,21};
int homeFrame[] = {1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500};

int home1[] = {1800, 1000, 1700, 1500, 1600, 1500, 1600, 1500, 1700, 1500, 1800, 1500};
int home2[] = {1800, 1500, 1700, 1500, 1600, 1500, 1600, 1500, 1700, 1500, 1800, 1500};
int home3[] = {1700, 1500, 1600, 1500, 1400, 1500, 1700, 1500, 1800, 1500, 1200, 2000};
int home4[] = {1700, 1500, 1600, 1500, 1400, 1500, 1700, 1500, 1800, 1500, 1200, 1500};
int home5[] = {1600, 1500, 1400, 1500, 1300, 1500, 1800, 1500, 1200, 2000, 1300, 1500};
int home6[] = {1600, 1500, 1400, 1500, 1300, 1500, 1800, 1500, 1200, 1500, 1300, 1500};

int home7[] = {1400, 1500, 1300, 1500, 1200, 1500, 1200, 2000, 1300, 1500, 1400, 1500};
int home8[] = {1400, 1500, 1300, 1500, 1200, 1500, 1200, 1500, 1400, 1500, 1400, 1500};
int home9[] = {1300, 1500, 1200, 1500, 1800, 1000, 1300, 1500, 1400, 1500, 1500, 1500};
int home10[] = {1300, 1500, 1200, 1500, 1800, 1500, 1300, 1500, 1400, 1500, 1500, 1500};
int home11[] = {1200, 1500, 1800, 1000, 1700, 1500, 1400, 1500, 1500, 1500, 1600,1500};
int home12[] = {1200, 1500, 1800, 1500, 1700, 1500, 1400, 1500, 1500, 1500, 1600, 1500};

void setup() {                
  mySSC32.begin(9600);
  mySSC32.enableServos(channels);
  mySSC32.setFrame(homeFrame);
  delay(1000);
  pinMode(13,OUTPUT);
}

void loop() {
  Serial.println(micros());
//  mySSC32.setFrame(channels,homeFrame);
  Serial.println(micros());

  mySSC32.setFrame(home1);
  delay(200);
  mySSC32.setFrame(home2);
  delay(200);
  mySSC32.setFrame(home3);
  delay(200);
  mySSC32.setFrame(home4);
  delay(200);
  mySSC32.setFrame(home5);
  delay(200);
  mySSC32.setFrame(home6);
  delay(200);

  mySSC32.setFrame(home7);
  delay(200);
  mySSC32.setFrame(home8);
  delay(200);
  mySSC32.setFrame(home9);
  delay(200);
  mySSC32.setFrame(home10);
  delay(200);
  mySSC32.setFrame(home11);
  delay(200);
  mySSC32.setFrame(home12);
  delay(200);
}