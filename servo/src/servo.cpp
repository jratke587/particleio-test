/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/workspaces/particleio-test/servo/src/servo.ino"
void setup();
void loop();
#line 1 "/workspaces/particleio-test/servo/src/servo.ino"
Servo myServo;
int servoPin = D2;
int potentiometer = A0;

void setup() {
  myServo.attach(servoPin);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(potentiometer);
  int angle = map(val, 0, 4096, 10, 170); //map the potentiometer value to an angle from 0 to 180 degrees
  Serial.println("> " + String(val));
  myServo.write(angle);
  delay(100);
}