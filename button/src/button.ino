int led = D3;
int led_builtin = D7;
int button = D5;

bool ledSwitch = true;

void setup() {
  pinMode(button, INPUT_PULLDOWN);
  pinMode(led, OUTPUT);
  pinMode(led_builtin, OUTPUT);
  digitalWrite(led, ledSwitch);
  digitalWrite(led_builtin, !ledSwitch);
}

void loop() {
  if (digitalRead(button)) {
    ledSwitch = !ledSwitch;
    digitalWrite(led, ledSwitch);
    digitalWrite(led_builtin, !ledSwitch);
  }
  while (digitalRead(button)) {
    delay(50);
  }
}