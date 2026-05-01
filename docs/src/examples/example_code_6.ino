#define D3 analog_Pin
#define D9 PWM_Pin

void setup(){
    pinMode(analogPin,INPUT);
    pinMode(PWMPin,INPUT);
}

void loop(){
    long PWM_duration = pulseIn(PWM_Pin,HIGH);
    int analogValue = analogRead(analog_Pin);

}