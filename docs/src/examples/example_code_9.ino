#include <Wire.h>

const uint8_t SHT31_ADDR = 0x45; 

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println("センサーの初期化完了。測定を開始します。");
}

void loop() {
  float tempSum = 0.0;
  float humSum = 0.0;
  uint8_t validSamples = 0; // 成功したサンプルのカウント用

  Serial.println("--- 10回のサンプリングを開始 ---");

  for (uint8_t i = 0; i < 10; i++) {
    
    Wire.beginTransmission(SHT3X_ADDR);
    Wire.write(0x24); 
    Wire.write(0x00); 
    Wire.endTransmission();

    delay(20); 

    Wire.requestFrom(SHT3X_ADDR, (uint8_t)6);

    if (Wire.available() == 6) {
      uint8_t rxData[6];
      for (uint8_t j = 0; j < 6; j++) {
        rxData[j] = Wire.read();
      }

      uint16_t tempRaw = (rxData[0] << 8) | rxData[1];
      uint16_t humRaw = (rxData[3] << 8) | rxData[4];

      float temperature = -45.0 + (175.0 * (float)tempRaw / 65535.0);
      float humidity = 100.0 * (float)humRaw / 65535.0;

      // 4. 合計値に加算
      tempSum += temperature;
      humSum += humidity;
      validSamples++;

    } else {
      Serial.println("データ受信エラー、このサンプルはスキップします。");
    }

    delay(50); 
  }

  if (validSamples > 0) {
    float avgTemp = tempSum / validSamples;
    float avgHum = humSum / validSamples;

    Serial.print("10回の平均値  温度: ");
    Serial.print(avgTemp, 3);
    Serial.print(" °C 湿度: ");
    Serial.print(avgHum, 3);
    Serial.println(" %");
  } else {
    Serial.println("有効なデータが取得できませんでした。");
  }

  delay(500); 
}