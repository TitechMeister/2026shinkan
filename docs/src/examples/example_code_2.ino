#define D0 LEDPin1

void setup(){
    pinMode(LEDPin1,OUTPUT);
}

void loop(){
    digitalWrite(LEDPin1,HIGH);
    delay(1000);
}