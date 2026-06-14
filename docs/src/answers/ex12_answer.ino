// 考え方: 割り込み関数ではmodeを書き換えるだけにします。LEDの点灯や点滅はloop()内のswitch文でmodeを見て切り替えます。

#define button D9

uint8_t led[3] = {D0, D1, D2};
volatile uint8_t mode = 0;

void buttonISR();

void setup() {
  for (uint8_t i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT);
  }

  pinMode(button, INPUT);
  attachInterrupt(digitalPinToInterrupt(button), buttonISR, FALLING);
}

void loop() {
  switch (mode) {
    case 0:
      for (uint8_t i = 0; i < 3; i++) {
        digitalWrite(led[i], HIGH);
      }
      delay(500);

      for (uint8_t i = 0; i < 3; i++) {
        digitalWrite(led[i], LOW);
      }
      delay(500);
      break;

    case 1:
      for (uint8_t i = 0; i < 3; i++) {
        digitalWrite(led[i], HIGH);
      }
      break;
  }
}

void buttonISR() {
  mode = 1;
}

