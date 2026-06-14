// 考え方: D1を出力に設定し、HIGHを出し続ければLED 2が点灯します。Lesson 01の範囲なので、使う命令はpinMode()とdigitalWrite()だけです。

void setup() {
  // D1 ピンを「出力用」に設定する
  pinMode(D1, OUTPUT);
}

void loop() {
  // D1 ピンから電圧を出力し続け、LEDを点灯させる
  digitalWrite(D1, HIGH);
}

