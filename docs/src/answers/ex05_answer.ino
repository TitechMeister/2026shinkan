// 考え方: ボタンの押下回数を数え、Serial.print()で回数を表示します。偶数か奇数かは、2で割った余りを使って判断します。

#define button D9
#define LED D0

uint8_t count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  if (digitalRead(button) == LOW) {
    count++;

    Serial.print("ボタンが");
    Serial.print(count);
    Serial.println("回押されてました");

    if (count % 2 == 0) {
      Serial.println("偶数回です");
      digitalWrite(LED, HIGH);
      delay(1000);
      digitalWrite(LED, LOW);
    } else {
      Serial.println("奇数回です");
    }

    while (digitalRead(button) == LOW) {
      delay(10);
    }
  }
}

