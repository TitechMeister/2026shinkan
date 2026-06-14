// 考え方: PWMはpulseIn()でHIGH時間を読み、アナログはanalogRead()で電圧に対応する値を読みます。どちらもデータシートの式に当てはめてcmへ変換します。

#define analog_Pin D3
#define PWM_Pin D8

void setup() {
  Serial.begin(9600);
  pinMode(analog_Pin, INPUT);
  pinMode(PWM_Pin, INPUT);
}

void loop() {
  long PWM_duration = pulseIn(PWM_Pin, HIGH);
  int analogValue = analogRead(analog_Pin);

  float pwmInches = (float)PWM_duration / 147.0;
  float pwmCm = pwmInches * 2.54;

  float analogInches = (float)analogValue * 512.0 / 1023.0;
  float analogCm = analogInches * 2.54;

  Serial.print("PWM Distance: ");
  Serial.print(pwmCm);
  Serial.println(" cm");

  Serial.print("Analog Distance: ");
  Serial.print(analogCm);
  Serial.println(" cm");

  delay(500);
}

