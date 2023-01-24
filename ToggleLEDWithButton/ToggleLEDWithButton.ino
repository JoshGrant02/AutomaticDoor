#define PINC 0x26
#define DDRC 0x27
#define PORTC 0x28
#define PCICR 0x68
#define PCMASK1 0x6C
#define EIMASK 0x3D
#define PIND 0x29
#define DDRD 0x2A
#define PORTD 0x2B
#define EIFR 0x3C

void pcint1_handler();

void setup() {
  *(uint8_t*) DDRC = (uint8_t) 0b00;
  *(uint8_t*) PORTC = (uint8_t) 0b10;
  *(uint8_t*) DDRD = (uint8_t) 0b01;//button output mode
  *(uint8_t*) PCICR = (uint8_t) 0b10;
  *(uint8_t*) PCMASK1 = (uint8_t) 0b10;
  //IMPLEMENT_ISR(0x0008, pcint1_handler);
  //*(uint32_t*) 0x0008 = (uint32_t) pcint1_handler;
  //pinMode(1, OUTPUT);
  attachInterrupt(0, pcint1_handler, CHANGE);
}

void loop() {
}

void pcint1_handler() {
  //Disable interrupt
  *(uint8_t*) EIMASK &= (uint8_t) ~0b1;

  bool pressed = (*(uint8_t*) PORTC) && 0b10;
  if (pressed) {
    *(uint8_t*) PINC = (uint8_t) 0b1;
  }

  //Re-enable interrupt after contact bounce
  *(uint8_t*) EIMASK |= (uint8_t) 0b1;
  *(uint8_t*) EIFR &= (uint8_t) 0b1;
}