#include "SSC32.h"
SSC32 mySSC32;
bool mybool = true;

// this constant won't change.  It's the pin number
// of the sensor's output:
const int pingPin = 8;
int channels[] = {0, 1, 2, 3, 4, 5, 16, 17, 18, 19, 20, 21};
int homeFrame[] = {1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500};
int home1[] = {1900, 1900, 1500, 1500, 1300, 1500, 1700, 1500, 1100, 1100, 1500, 1500};
int home2[] = {1500, 1500, 1300, 1500, 1900, 1900, 1100, 1100, 1500, 1500, 1700, 1500};
int home3[] = {1300, 1500, 1900, 1900, 1500, 1500, 1500, 1500, 1700, 1500, 1100, 1100};

void setup() {
  // initialize serial communication:
  mySSC32.begin(9600);
  mySSC32.enableServos(channels);
  mySSC32.setFrame(homeFrame);
  pinMode(13, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  if (cm < 40)
  {
    mySSC32.setFrame(homeFrame);
    delay(500);

  }
  else
  {
    mySSC32.setFrame(home1);
    delay(500) ;
    mySSC32.setFrame(home2);
    delay(500);
    mySSC32.setFrame(home3);
    delay(500);


  }

  // Serial.print(inches);
  //Serial.print("in, ");
  //Serial.print(cm);
  //Serial.print("cm");
  //Serial.println();
  delay(100);
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per.
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
