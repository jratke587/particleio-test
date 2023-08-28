/*
 * Project blink
 * Description:
 * Author:
 * Date:
 */

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D3, OUTPUT);
  pinMode(A0, INPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  for(int i = 0; i < 3; i++) {
    digitalWrite(D3, HIGH);
    delay(500);
    digitalWrite(D3, LOW);
    delay(500);
  }
  for (int x = 0; x < 2; x++) {
    for (int i=0; i<255; i++) {
      analogWrite(D3, i);
      delay(3.92);
    }
    for (int i=255; i>0; i--) {
      analogWrite(D3, i);
      delay(3.92);
    }
  }
  delay(500);
  uint32_t analogValue = analogRead(A0);
  Particle.publish(String(analogValue));
}