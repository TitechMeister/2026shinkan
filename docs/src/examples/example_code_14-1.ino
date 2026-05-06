#define ButtonPin D9
#define LED1 D0
#define LED2 D1

void setup(){
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(ButtonPin,INPUT);
}

void loop(){
    
    digitalWrite(LED1,HIGH);
    delay(3000);
    digitalWrite(LED1,LOW);
    delay(3000);

    if(digitalRead(ButtonPin) == LOW){
        digitalWrite(LED2,HIGH);
        delay(3000);
        digitalWrite(LED2,LOW);
    }
}