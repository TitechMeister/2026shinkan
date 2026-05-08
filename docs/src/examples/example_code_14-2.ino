#define ButtonPin D9
#define LED1 D0
#define LED2 D1

bool LEDOnOff = true;
long previousTime = 0;

void setup(){
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(ButtonPin,INPUT);

    previousTime = millis();
}

void loop(){

    long currentTime = millis();

    if(currentTime - previousTime > 3000){
        previousTime = millis();
        LEDOnOff = !LEDOnOff;
    }

    if(LEDOnOff == true){
        digitalWrite(LED1,HIGH);
    }

    if(LEDOnOff == false){
        digitalWrite(LED1,LOW);
    }
    
    if(digitalRead(ButtonPin) == LOW){
        digitalWrite(LED2,HIGH);
    }else{
        digitalWrite(LED2,LOW);
    }
}