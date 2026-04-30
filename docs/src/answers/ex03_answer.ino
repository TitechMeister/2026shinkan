uint8_t led[3] = {D0, D1, D2};

void setup() {
  for(uint8_t i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  for(uint8_t i = 0; i < 3; i++) {
    digitalWrite(led[i], HIGH);
    delay(1000);
    digitalWrite(led[i], LOW);
  }
}
