// 考え方: 温度、湿度、距離の合計と回数をstructにまとめます。20msごとに1回ずつ足し込み、10回たまったら平均を表示します。

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

void addSample(SensorData &data, float value);
void printAverage(const char *label, SensorData &data, const char *unit);
void updateSht31();
void updateDistance();

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Wire.begin();
  sht31.begin(SHT31_ADDR);
}

void loop() {
  updateSht31();
  updateDistance();
}

void addSample(SensorData &data, float value) {
  data.sum += value;
  data.count++;
}

void printAverage(const char *label, SensorData &data, const char *unit) {
  if (data.count >= 10) {
    float average = data.sum / data.count;

    Serial.print(label);
    Serial.print(": ");
    Serial.print(average);
    Serial.println(unit);

    data.sum = 0.0;
    data.count = 0;
  }
}

void updateSht31() {
  unsigned long currentTime = millis();

  if (currentTime - previousShtTime < 20) {
    return;
  }

  previousShtTime = currentTime;

  float temperature = sht31.readTemperature();
  float humidity = sht31.readHumidity();

  addSample(temperatureData, temperature);
  addSample(humidityData, humidity);

  printAverage("Temperature", temperatureData, " C");
  printAverage("Humidity", humidityData, " %");
}

void updateDistance() {
  unsigned long currentTime = millis();

  if (currentTime - previousDistanceTime < 20) {
    return;
  }

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

      addSample(distanceData, cm);
      printAverage("Distance", distanceData, " cm");
    }
  }
}

