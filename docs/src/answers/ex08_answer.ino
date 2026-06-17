// 考え方: 周期的連続測定はsetup()で開始し、loop()では2秒ごとに1回分のデータを読み出します。10回読んだら停止コマンドを送り、LEDを点灯させてwhile(true)で止めます。

#include <Wire.h>

const uint8_t SHT31_ADDR = 0x45;
#define LED D0

uint8_t count = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(LED, OUTPUT);

  Wire.beginTransmission(SHT31_ADDR);
  Wire.write(0x20);
  Wire.write(0x24);
  Wire.endTransmission();
}

void loop() {
  delay(2000);

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

    Serial.print("温度: ");
    Serial.println(temperature);
    Serial.print("湿度: ");
    Serial.println(humidity);

    count++;
  }

  if (count >= 10) {
    Wire.beginTransmission(SHT31_ADDR);
    Wire.write(0x30);
    Wire.write(0x93);
    Wire.endTransmission();

    digitalWrite(LED, HIGH);
    while (true) {
    }
  }
}
