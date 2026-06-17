// 考え方: 温度、湿度、距離の合計と回数をstructにまとめます。200msごとに1回ずつ足し込み、10回たまったら平均を表示します。

#include <Wire.h>
#include <Adafruit_SHT31.h>

const uint8_t SHT31_ADDR = 0x45;

Adafruit_SHT31 sht31;

struct SensorData {
  float sum;
  uint8_t count;
};

SensorData temperatureData = {0.0, 0};
SensorData humidityData = {0.0, 0};
SensorData distanceData = {0.0, 0};

unsigned long previousShtTime = 0;
unsigned long previousDistanceTime = 0;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Wire.begin();
  sht31.begin(SHT31_ADDR);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousShtTime >= 200) {
    previousShtTime = currentTime;

    float temperature = sht31.readTemperature();
    float humidity = sht31.readHumidity();

    temperatureData.sum += temperature;
    temperatureData.count++;

    humidityData.sum += humidity;
    humidityData.count++;

    if (temperatureData.count >= 10) {
      float averageTemperature = temperatureData.sum / temperatureData.count;

      Serial.print("Temperature: ");
      Serial.print(averageTemperature);
      Serial.println(" C");

      temperatureData.sum = 0.0;
      temperatureData.count = 0;
    }

    if (humidityData.count >= 10) {
      float averageHumidity = humidityData.sum / humidityData.count;

      Serial.print("Humidity: ");
      Serial.print(averageHumidity);
      Serial.println(" %");

      humidityData.sum = 0.0;
      humidityData.count = 0;
    }
  }

  if (currentTime - previousDistanceTime >= 200) {
    previousDistanceTime = currentTime;

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

        distanceData.sum += cm;
        distanceData.count++;

        if (distanceData.count >= 10) {
          float averageDistance = distanceData.sum / distanceData.count;

          Serial.print("Distance: ");
          Serial.print(averageDistance);
          Serial.println(" cm");

          distanceData.sum = 0.0;
          distanceData.count = 0;
        }
      }
    }
  }
}
