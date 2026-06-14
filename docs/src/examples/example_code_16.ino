#define analog_Pin D3
#define PWM_Pin D8

struct SensorData {
    unsigned long add;
    uint8_t validTime;
    float avg;
    float result;
};

SensorData analogDistance;
SensorData PWMDistance;

void setup(){
    pinMode(analog_Pin,INPUT);
    pinMode(PWM_Pin,INPUT);
    Serial.begin(9600);
}

void loop(){

    for(uint8_t i = 0; i < 10; i ++){
        analogDistance.add += analogRead(analog_Pin);
        analogDistance.validTime ++;
        delay(50);
    }

    for(uint8_t i = 0; i < 10; i ++){
        PWMDistance.add += pulseIn(PWM_Pin,HIGH);
        PWMDistance.validTime ++;
        delay(50);
    }

    analogDistance.avg = (float)analogDistance.add / analogDistance.validTime;
    PWMDistance.avg = (float)PWMDistance.add / PWMDistance.validTime;

    analogDistance.result = analogDistance.avg / 147.0 * 2.54;
    PWMDistance.result = PWMDistance.avg * 1.27;

    Serial.print("analogDistance :");
    Serial.println(analogDistance.result);
    Serial.print("PWMDistance :");
    Serial.println(PWMDistance.result);

    analogDistance.add = 0;
    analogDistance.validTime = 0;
    PWMDistance.add = 0;
    PWMDistance.validTime = 0;
}
