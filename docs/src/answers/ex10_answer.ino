// 考え方: ボタン判定とセンサ読み取りを別々の関数に分けます。loop()では、ボタンが押されていないときだけセンサ読み取り関数を呼びます。

#include <Wire.h>

#define button D9

const uint8_t SHT31_ADDR = 0x45;

bool Button_push(uint8_t buttonPin);
void readSensor(uint8_t address, unsigned long waitTime);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(button, INPUT);
}

void loop() {
  if (!Button_push(button)) {
    readSensor(SHT31_ADDR, 1000);
  }
}

bool Button_push(uint8_t buttonPin) {
  if (digitalRead(buttonPin) == LOW) {
    return true;
  }

  return false;
}

void readSensor(uint8_t address, unsigned long waitTime) {
  Wire.beginTransmission(address);
  Wire.write(0x24);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(20);

  Wire.requestFrom(address, (uint8_t)6);

  if (Wire.available() == 6) {
    uint8_t Data[6];

    for (uint8_t i = 0; i < 6; i++) {
      Data[i] = Wire.read();
    }

    uint16_t tempRaw = (Data[0] << 8) | Data[1];
    uint16_t humRaw = (Data[3] << 8) | Data[4];

    float temperature = -45.0 + (175.0 * (float)tempRaw / 65535.0);
    float humidity = 100.0 * (float)humRaw / 65535.0;

    Serial.print("温度: ");
    Serial.println(temperature);
    Serial.print("湿度: ");
    Serial.println(humidity);
  }

  delay(waitTime);
}

