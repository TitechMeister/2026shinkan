#define button D9

// 必要なグローバル変数は「カウント」だけ
uint8_t count = 0;

void setup() {
    Serial.begin(9600);
    pinMode(D0, OUTPUT);
    pinMode(button, INPUT);
}

void loop() {
  // ボタンが押されているかをチェック
    if (digitalRead(button) == LOW) {
    count++; // カウントを1増やす
    
    // 指が離されるまで、ここで処理を止めて待機する（連打・長押し判定を防ぐ）
    while (digitalRead(button) == LOW) {
        delay(10);
    }
    Serial.print("ボタンが");
    Serial.print(count);
    Serial.println("回押されました");
    }
}
