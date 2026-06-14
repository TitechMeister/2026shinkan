// 考え方: LEDの状態遷移とUART読み取りを別々のタイマーで動かします。どちらもdelay()を使わず、時間が来たかどうかを毎回確認します。

uint8_t led[3] = {D0, D1, D2};

unsigned long previousLedTime = 0;
unsigned long previousSensorTime = 0;

enum class Status {
  LED1ON,
  LED2ON,
  LED3ON
};

Status LEDstate = Status::LED1ON;

void updateLed();
void readUartDistance();

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  for (uint8_t i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  updateLed();
  readUartDistance();
}

void updateLed() {
  unsigned long currentTime = millis();

  if (currentTime - previousLedTime < 3000) {
    return;
  }

  previousLedTime = currentTime;

  switch (LEDstate) {
    case Status::LED1ON:
      digitalWrite(led[0], HIGH);
      digitalWrite(led[1], LOW);
      digitalWrite(led[2], LOW);
      LEDstate = Status::LED2ON;
      break;

    case Status::LED2ON:
      digitalWrite(led[0], LOW);
      digitalWrite(led[1], HIGH);
      digitalWrite(led[2], LOW);
      LEDstate = Status::LED3ON;
      break;

    case Status::LED3ON:
      digitalWrite(led[0], LOW);
      digitalWrite(led[1], LOW);
      digitalWrite(led[2], HIGH);
      LEDstate = Status::LED1ON;
      break;
  }
}

void readUartDistance() {
  unsigned long currentTime = millis();

  if (currentTime - previousSensorTime < 5000) {
    return;
  }

  previousSensorTime = currentTime;

  int SonicData[5] = {0, 0, 0, 0, 0};

  if (Serial1.available() >= 5) {
    SonicData[0] = Serial1.read();

    if (SonicData[0] == 'R') {
      for (uint8_t i = 1; i < 5; i++) {
        SonicData[i] = Serial1.read();
      }

      int inches = (SonicData[1] - '0') * 100;
      inches += (SonicData[2] - '0') * 10;
      inches += SonicData[3] - '0';

      float cm = (float)inches * 2.54;

      Serial.print("Distance: ");
      Serial.print(cm);
      Serial.println(" cm");
    }
  }
}

