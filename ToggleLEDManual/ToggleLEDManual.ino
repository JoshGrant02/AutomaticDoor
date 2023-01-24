#define PINC 0x26
#define DDRC 0x27
#define PORTC 0x28

void setup() {
  *(uint8_t*) DDRC = (uint8_t) 0b1;
  *(uint8_t*) PORTC = (uint8_t) 0b1;
}

void loop() {
  delay(1000);
  *(uint8_t*) PINC |= (uint8_t) 0b1;
}
