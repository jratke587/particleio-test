int potentiometer = A0;
int ledPins[3] = {D4, D3, D6};
int numLeds = sizeof(ledPins) / sizeof(ledPins[0]); //length of ledPins
int ledIndex = 0; 

void setup() {
  pinMode(potentiometer, INPUT);
  for (int i=0; i<numLeds; i++) { //set all ledPins as output
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i=0; i<numLeds; i++) {
    digitalWrite(ledPins[i], ledIndex == i); //set led HIGH if it's index matches ledIndex, othewise low
  }
  ledIndex = (ledIndex + 1) % numLeds; //increment or reset ledIndex
  int val = analogRead(potentiometer);
  int delayTime = map(val, 0, 4096, 100, 1500); //convert analog value to a range from 100 to 1500
  delay(delayTime);
}