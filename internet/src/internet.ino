#include <env.h>
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(secretvalue);
  delay(1000);
}