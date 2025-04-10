#include <Servo.h>


int servoPin = 9;
float servoPos = 0;
int photoDetectivePin = A0;
int lightVal;
int dt = 1000;

Servo myServo;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(servoPin);
pinMode(photoDetectivePin, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

//read light value and input it into a function that is custom to my setup
//when sunny should put servo at a 180 degree angle ELSE it puts it lower
//zero signifies nightime
lightVal = analogRead(photoDetectivePin);
servoPos = ((18.0/41.0)*lightVal) - 87.8; // NOTE: have to make 18.0 and 41.0 as floats otherwise will just return 0 to show 18 is < 41 weird C++ mechanism
myServo.write(servoPos);


//This code for the tests
Serial.println(servoPos);
Serial.println(lightVal);
delay(dt);


}
