#include <Wire.h>
#include <Adafruit_SHT31.h>

const uint8_t SHT31_ADDR = 0x45;

Adafruit_SHT31 sht31;

union FloatBytes {
    float value;
    uint8_t bytes[4];
};

FloatBytes temperature;

void setup() {
    Serial.begin(9600);
    Wire.begin();
    sht31.begin(SHT31_ADDR);
}

void loop() {
    temperature.value = sht31.readTemperature();

    Serial.print("temperature: ");
    Serial.println(temperature.value);

    for(uint8_t i = 0; i < 4; i++) {
        Serial.print("byte ");
        Serial.print(i);
        Serial.print(": 0x");
        Serial.println(temperature.bytes[i], HEX);
    }

    Serial.println();
    delay(1000);
}
