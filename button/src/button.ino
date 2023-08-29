void setup() {
  pinMode(D5, INPUT_PULLDOWN);
  pinMode(D3, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  if (digitalRead(D5)) {
    for (int i = 0; i < 10; i++) {
      delay(50);
      digitalWrite(D3, LOW);
      delay(50);
      digitalWrite(D3, HIGH);
    }
  } else {
    digitalWrite(D3, HIGH);
    delay(500);
    digitalWrite(D3, LOW);
    delay(500);
  }
}