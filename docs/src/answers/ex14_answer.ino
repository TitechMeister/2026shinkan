// 考え方: LED用とセンサ用で別々のpreviousTimeを持ちます。millis()の差が指定時間を超えたときだけ、それぞれの処理を実行します。

#include <Wire.h>
#include <Adafruit_SHT31.h>

#define LED D0

const uint8_t SHT31_ADDR = 0x45;

Adafruit_SHT31 sht31;

unsigned long previousLedTime = 0;
unsigned long previousSensorTime = 0;
bool ledState = false;

void updateLed();
void updateSensor();

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  sht31.begin(SHT31_ADDR);
}

void loop() {
  updateLed();
  updateSensor();
}

void updateLed() {
  unsigned long currentTime = millis();

  if (currentTime - previousLedTime >= 3000) {
    previousLedTime = currentTime;
    ledState = !ledState;
    digitalWrite(LED, ledState);
  }
}

void updateSensor() {
  unsigned long currentTime = millis();

  if (currentTime - previousSensorTime >= 2000) {
    previousSensorTime = currentTime;

    float temperature = sht31.readTemperature();
    float humidity = sht31.readHumidity();

    Serial.print("温度: ");
    Serial.println(temperature);
    Serial.print("湿度: ");
    Serial.println(humidity);
  }
}

