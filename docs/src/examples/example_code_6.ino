#define analog_Pin D3
#define PWM_Pin D8

void setup(){
    pinMode(analog_Pin,INPUT);
    pinMode(PWM_Pin,INPUT);
}

void loop(){
    long PWM_duration = pulseIn(PWM_Pin,HIGH);
    int analogValue = analogRead(analog_Pin);

}
