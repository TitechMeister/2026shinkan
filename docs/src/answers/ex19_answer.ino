// 考え方: 関数に距離を入れる変数のアドレスを渡し、関数の中でanalog距離とPWM距離の2つを書き込みます。

#define analog_Pin D3
#define PWM_Pin D8

void readDistance(float* analogCm, float* pwmCm);

void setup() {
  Serial.begin(9600);
  pinMode(analog_Pin, INPUT);
  pinMode(PWM_Pin, INPUT);
}

void loop() {
  float analogDistance = 0.0;
  float pwmDistance = 0.0;

  readDistance(&analogDistance, &pwmDistance);

  Serial.print("Analog Distance: ");
  Serial.print(analogDistance);
  Serial.println(" cm");

  Serial.print("PWM Distance: ");
  Serial.print(pwmDistance);
  Serial.println(" cm");

  delay(1000);
}

void readDistance(float* analogCm, float* pwmCm) {
  int analogValue = analogRead(analog_Pin);
  long pwmDuration = pulseIn(PWM_Pin, HIGH);

  float analogInches = (float)analogValue * 512.0 / 1023.0;
  *analogCm = analogInches * 2.54;

  float pwmInches = (float)pwmDuration / 147.0;
  *pwmCm = pwmInches * 2.54;
}
