// 考え方: 10回分の温度と湿度を合計し、countで割って平均を出します。表示した後は、次の10回に向けて合計と回数を0に戻します。

#include <Wire.h>

const uint8_t SHT31_ADDR = 0x45;

float tempSum = 0.0;
float humSum = 0.0;
uint8_t count = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Wire.beginTransmission(SHT31_ADDR);
  Wire.write(0x21);
  Wire.write(0x30);
  Wire.endTransmission();
}

void loop() {
  delay(1000);

  Wire.beginTransmission(SHT31_ADDR);
  Wire.write(0xE0);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.requestFrom(SHT31_ADDR, (uint8_t)6);

  if (Wire.available() == 6) {
    uint8_t Data[6];

    for (uint8_t i = 0; i < 6; i++) {
      Data[i] = Wire.read();
    }

    uint16_t tempRaw = (Data[0] << 8) | Data[1];
    uint16_t humRaw = (Data[3] << 8) | Data[4];

    float temperature = -45.0 + (175.0 * (float)tempRaw / 65535.0);
    float humidity = 100.0 * (float)humRaw / 65535.0;

    tempSum += temperature;
    humSum += humidity;
    count++;
  }

  if (count >= 10) {
    float avgTemp = tempSum / count;
    float avgHum = humSum / count;

    Serial.print("平均温度: ");
    Serial.println(avgTemp, 4);
    Serial.print("平均湿度: ");
    Serial.println(avgHum, 4);

    tempSum = 0.0;
    humSum = 0.0;
    count = 0;
  }
}

