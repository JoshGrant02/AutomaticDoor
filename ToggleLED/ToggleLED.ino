void setup() {
  pinMode(PIN_A0, OUTPUT);
}

void loop() {
  digitalWrite(PIN_A0, HIGH);
  delay(1000);
  digitalWrite(PIN_A0, LOW);
  delay(1000);
}
