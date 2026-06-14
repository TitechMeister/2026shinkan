// 考え方: UARTで届く距離は文字です。3桁の数字文字をそれぞれ数値へ変換し、百の位、十の位、一の位として合成します。

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  int SonicData[5] = {0, 0, 0, 0, 0};

  if (Serial1.available()) {
    SonicData[0] = Serial1.read();

    if (SonicData[0] == 'R') {
      for (uint8_t i = 1; i < 5; i++) {
        while (!Serial1.available());
        SonicData[i] = Serial1.read();
      }

      int hundreds = SonicData[1] - '0';
      int tens = SonicData[2] - '0';
      int ones = SonicData[3] - '0';

      int inches = hundreds * 100 + tens * 10 + ones;
      float cm = (float)inches * 2.54;

      Serial.print("Distance: ");
      Serial.print(cm);
      Serial.println(" cm");
    }
  }
}

