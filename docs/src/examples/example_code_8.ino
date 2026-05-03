#include <Wire.h>

const uint8_t SDT31_ADDR = 0x45;

void setup(){
    Serial.begin(9600);
    Wire.begin();
    Serial.println("センサーの初期化完了。測定を開始します。");
}

void loop(){
    Wire.beginTransmission(SDT31_ADDR);
    Wire.write(0x24);
    Wire.write(0x00);
    Wire.endTransmission();

    delay(20);

    Wire.requestFrom(SDT31_ADDR,6);

    if(Wire.available() == 6){
        uint8_t Data[6];
        for(uint8_t i = 0; i < 6; i ++){
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
    }else{
        Serial.println("通信エラー");
    }

    delay(1000);
}