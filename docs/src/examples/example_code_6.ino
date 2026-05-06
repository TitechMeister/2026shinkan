#define analog_Pin D3
#define PWM_Pin D9

void setup(){
    pinMode(analogPin,INPUT);
    pinMode(PWMPin,INPUT);
}

void loop(){
    long PWM_duration = pulseIn(PWM_Pin,HIGH);
    int analogValue = analogRead(analog_Pin);

}