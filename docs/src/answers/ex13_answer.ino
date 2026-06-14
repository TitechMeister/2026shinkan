// 考え方: LED1、LED2、LED3の点滅状態をenum classで管理します。各状態で1回点滅し、countが5になったら次の状態へ進みます。

uint8_t led[3] = {D0, D1, D2};
uint8_t count = 0;

enum class Status {
  LED1_BLINK,
  LED2_BLINK,
  LED3_BLINK
};

Status state = Status::LED1_BLINK;

void blinkLed(uint8_t pin);

void setup() {
  for (uint8_t i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  switch (state) {
    case Status::LED1_BLINK:
      blinkLed(led[0]);
      count++;
      if (count >= 5) {
        count = 0;
        state = Status::LED2_BLINK;
      }
      break;

    case Status::LED2_BLINK:
      blinkLed(led[1]);
      count++;
      if (count >= 5) {
        count = 0;
        state = Status::LED3_BLINK;
      }
      break;

    case Status::LED3_BLINK:
      blinkLed(led[2]);
      count++;
      if (count >= 5) {
        count = 0;
        state = Status::LED1_BLINK;
      }
      break;
  }
}

void blinkLed(uint8_t pin) {
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}

