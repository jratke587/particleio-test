int led = D3;
int led2 = D4;
int button = D5;

bool ledSwitch = true;

void setup() {
  pinMode(button, INPUT_PULLDOWN);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led, ledSwitch);
  digitalWrite(led2, !ledSwitch);
}

void loop() {
  if (digitalRead(button)) {
    ledSwitch = !ledSwitch;
    digitalWrite(led, ledSwitch);
    digitalWrite(led2, !ledSwitch);
  }
  while (digitalRead(button)) {
    delay(50);
  }
}