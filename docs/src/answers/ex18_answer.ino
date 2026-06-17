// 考え方: unionを使うと、floatの距離データをそのまま値として扱いつつ、同じ中身を1バイトずつ確認できます。

#define analog_Pin D3

union FloatBytes {
  float value;
  uint8_t bytes[4];
};

FloatBytes distanceData;

void setup() {
  Serial.begin(9600);
  pinMode(analog_Pin, INPUT);
}

void loop() {
  int analogValue = analogRead(analog_Pin);

  float analogInches = (float)analogValue * 512.0 / 1023.0;
  distanceData.value = analogInches * 2.54;

  Serial.print("Distance: ");
  Serial.print(distanceData.value);
  Serial.println(" cm");

  for (uint8_t i = 0; i < 4; i++) {
    Serial.print("byte ");
    Serial.print(i);
    Serial.print(": 0x");
    Serial.println(distanceData.bytes[i], HEX);
  }

  Serial.println();
  delay(1000);
}
