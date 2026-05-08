#define LEDPin1 D0

void setup(){
    pinMode(LEDPin1,OUTPUT);
}

void loop(){
    digitalWrite(LEDPin1,HIGH);
    delay(1000);
    digitalWrite(LEDPin1,LOW);
    delay(1000);
}