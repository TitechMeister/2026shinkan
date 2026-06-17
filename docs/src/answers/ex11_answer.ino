// 考え方: ライブラリを使うと、温度はreadTemperature()、湿度はreadHumidity()で読めます。I2Cの細かい処理はライブラリの中に隠れています。

#include <Wire.h>
#include <Adafruit_SHT31.h>

const uint8_t SHT31_ADDR = 0x45;

Adafruit_SHT31 sht31;

void setup() {
  Serial.begin(9600);
  sht31.begin(SHT31_ADDR);
}

void loop() {
  float temperature = sht31.readTemperature();
  float humidity = sht31.readHumidity();

  Serial.print("温度: ");
  Serial.println(temperature);
  Serial.print("湿度: ");
  Serial.println(humidity);

  delay(1000);
}

