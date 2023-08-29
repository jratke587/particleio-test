bool ledSwitch = true;

void setup() {
  pinMode(D5, INPUT_PULLDOWN);
  pinMode(D3, OUTPUT);
  pinMode(D7, OUTPUT);
  digitalWrite(D3, ledSwitch);
  digitalWrite(D7, !ledSwitch);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  if (digitalRead(D5)) {
    ledSwitch = !ledSwitch;
    digitalWrite(D3, ledSwitch);
    digitalWrite(D7, !ledSwitch);
  }
  while (digitalRead(D5)) {
    delay(50);
  }
}