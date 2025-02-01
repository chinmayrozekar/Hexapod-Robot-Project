#include "SSC32.h"
SSC32 mySSC32;
bool mybool = true;


const int pingPin = 8;
int channels[] = {0, 1, 2, 3, 4, 5, 16, 17, 18, 19, 20, 21};
int homeFrame[] = {1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500};
int home1[] = {1900, 1100, 1300, 1900, 1900, 1100, 1900, 1100, 1300, 1900, 1900, 1100};
int home2[] = {1300, 1100, 1900, 1900, 1300, 1100, 1300, 1100, 1900, 1900, 1300, 1100};
int home3[] = {1300, 1900, 1900, 1100, 1300, 1900, 1300, 1900, 1900, 1100, 1300, 1900};
int home4[] = {1900, 1900, 1300, 1100, 1900, 1900, 1900, 1900, 1300, 1100, 1900, 1900};
int home5[]=  {1800, 1900, 1500, 1500, 1300, 1500, 1300, 1500, 1500, 1500, 1800, 1100};
int home6[]=  {1800,  900, 1500, 1500, 1800, 1900, 1800, 1100, 1500, 1500, 1800, 1500};
int home7[]=  {1800,  900, 1500, 1900, 1800, 1500, 1800, 1500, 1500, 1100, 1800, 1500};
int home8[]=  {1300,  900, 1500, 1900, 1300, 1300, 1300, 1500, 1500, 1100, 1300, 1100};
void setup() {
  // initialize serial communication:
  mySSC32.begin(9600);
  mySSC32.enableServos(channels);
  mySSC32.setFrame(homeFrame);
  pinMode(13, OUTPUT);
  
}

void loop() {
  
  long duration, inches, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  if (inches < 10)
  {
 for (int i=0; i <= 3; i++)
  mySSC32.setFrame(home5);
  delay(100);
  mySSC32.setFrame(home6);
  delay(200);

  mySSC32.setFrame(home7);
  delay(100);
  mySSC32.setFrame(home8);
  delay(200);
  }
  else
  {
  mySSC32.setFrame(home1);
  delay(200);
  mySSC32.setFrame(home2);
  delay(200);

  mySSC32.setFrame(home3);
  delay(200);
  mySSC32.setFrame(home4);
  delay(200);
  }

}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
