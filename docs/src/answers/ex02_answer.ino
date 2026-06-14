// 考え方: 3つのLEDを順番に点灯させるため、点灯したら待つ、消灯する、次のLEDへ進む、という流れを繰り返します。Lesson 02で学んだ#defineとdelay()を使います。

#define LED1 D0
#define LED2 D1
#define LED3 D2

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // D0 点灯消灯
  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  
  // D1 点灯消灯
  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED2, LOW);
  
  // D2 点灯、他を消灯
  digitalWrite(LED3, HIGH);
  delay(1000);
  digitalWrite(LED3, LOW);
}

