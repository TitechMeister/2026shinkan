// 考え方: センサ1個分の測定状態をclassにまとめます。privateに内部変数、publicに外から呼ぶ関数を置き、update()が呼ばれるたびに必要なら1回測定します。

#define analog_Pin D3
#define PWM_Pin D8

class SensorCalcu {
  private:
    uint8_t pin;
    unsigned long add;
    uint8_t count;
    unsigned long previousTime;
    unsigned long interval;
    bool usePulse;

  public:
    float result;
    bool ready;

    SensorCalcu(uint8_t setPin, bool pulseMode) {
      pin = setPin;
      usePulse = pulseMode;
      add = 0;
      count = 0;
      previousTime = 0;
      interval = 50;
      result = 0.0;
      ready = false;
    }

    void begin() {
      pinMode(pin, INPUT);
    }

    void update() {
      unsigned long currentTime = millis();

      if (currentTime - previousTime < interval) {
        return;
      }

      previousTime = currentTime;

      if (usePulse) {
        add += pulseIn(pin, HIGH);
      } else {
        add += analogRead(pin);
      }

      count++;

      if (count >= 10) {
        float average = (float)add / count;

        if (usePulse) {
          result = (average / 147.0) * 2.54;
        } else {
          result = (average * 512.0 / 1023.0) * 2.54;
        }

        add = 0;
        count = 0;
        ready = true;
      }
    }

    void clearReady() {
      ready = false;
    }
};

SensorCalcu analogDistance(analog_Pin, false);
SensorCalcu PWMDistance(PWM_Pin, true);

void setup() {
  Serial.begin(9600);
  analogDistance.begin();
  PWMDistance.begin();
}

void loop() {
  analogDistance.update();
  PWMDistance.update();

  if (analogDistance.ready) {
    Serial.print("Analog Distance: ");
    Serial.print(analogDistance.result);
    Serial.println(" cm");
    analogDistance.clearReady();
  }

  if (PWMDistance.ready) {
    Serial.print("PWM Distance: ");
    Serial.print(PWMDistance.result);
    Serial.println(" cm");
    PWMDistance.clearReady();
  }
}

