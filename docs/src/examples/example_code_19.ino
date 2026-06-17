#include <Wire.h>
#include <Adafruit_SHT31.h>

const uint8_t SHT31_ADDR = 0x45;

Adafruit_SHT31 sht31;

void readSHT31(float* temperature, float* humidity);

void setup() {
    Serial.begin(9600);
    Wire.begin();
    sht31.begin(SHT31_ADDR);
}

void loop() {
    float temp = 0.0;
    float hum = 0.0;

    readSHT31(&temp, &hum);

    Serial.print("temperature: ");
    Serial.println(temp);
    Serial.print("humidity: ");
    Serial.println(hum);

    delay(1000);
}

void readSHT31(float* temperature, float* humidity) {
    *temperature = sht31.readTemperature();
    *humidity = sht31.readHumidity();
}
