int ledPin = D4;
int buttonPin = D5;

bool ignoreEvents = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLDOWN);
  digitalWrite(ledPin, LOW);
  Particle.function("blink", blinkLED);
  Particle.function("disable", disableEvents);
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
  if (!ignoreEvents) {
    Particle.publish("blinkNextArgon");
  }
}

int disableEvents(String param) {
  ignoreEvents = !ignoreEvents;
  return ignoreEvents;
}