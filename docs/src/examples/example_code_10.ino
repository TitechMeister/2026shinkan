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

  Serial.print("温度: ");
  Serial.println(temperature);

  delay(1000);
}