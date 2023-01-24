// #define PINC 0x26
// #define DDRC 0x27
// #define PORTC 0x28

// uint8_t directionCounter = 0;

// void setup() {
//   *(uint8_t*) DDRC = (uint8_t) 0b11;
//   *(uint8_t*) PORTC = (uint8_t) 0b11;
//   digitalWrite();
// }

// //
// void loop() {
//   delay(50);
//   directionCounter++;
//   if (directionCounter == 200) {
//       *(uint8_t*) PINC = (uint8_t) 0b11;
//       directionCounter = 0;
//   }
//   else {
//       *(uint8_t*) PINC = (uint8_t) 0b1;
//   }
// }

#define step 5
#define dir 6
#define btn 7

void setup() {
  pinMode(step, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  digitalWrite(step, 0);
  digitalWrite(dir, 1);
  delay(5000); // 5 secs
}

//
void loop() {
  if (digitalRead(btn) == 0) {
    digitalWrite(step, 1);
    delay(1);
    digitalWrite(step, 0);
    delay(1);
  }
}

