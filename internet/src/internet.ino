int ledPin = D4;
int buttonPin = D5;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLDOWN);
  digitalWrite(ledPin, LOW);
  Particle.function("blink", blinkLED);
}

void loop() {
  if(digitalRead(buttonPin)) {
    callNextArgon();
    while (digitalRead(buttonPin)) {
      delay(50);
    }
  }
  delay(50);
}

int blinkLED(String param) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    callNextArgon();
    delay(1000);
    digitalWrite(ledPin, LOW);
    return 0;
}

void callNextArgon() {
  Particle.publish("blinkNextArgon");
}