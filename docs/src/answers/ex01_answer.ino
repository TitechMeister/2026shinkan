void setup() {
  // D1 ピンを「出力用」に設定する
  pinMode(D1, OUTPUT);
}

void loop() {
  // D1 ピンから電圧を出力し続け、LEDを点灯させる
  digitalWrite(D1, HIGH);
}
