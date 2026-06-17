#define button D9
const uint8_t led[3] = {D0,D1,D2};

void LED_onoff(uint8_t LEDPin, unsigned long delayTime);
bool Button_push(uint8_t buttonPin);

void setup(){
    for(uint8_t i = 0; i < 3; i ++){
        pinMode(led[i],OUTPUT);
    }
    pinMode(button,INPUT);
}

void loop(){
    if(Button_push(button)){
        for(uint8_t i = 0; i < 3; i ++){
            LED_onoff(led[i], 500);
        }
    }else{
        for(uint8_t i = 0; i < 3; i++){
            digitalWrite(led[i],LOW);
        }
    }
}

void LED_onoff(uint8_t LEDPin, unsigned long delayTime){
    digitalWrite(LEDPin,HIGH);
    delay(delayTime);
    digitalWrite(LEDPin,LOW);
    delay(delayTime);
}

bool Button_push(uint8_t buttonPin){
    if(digitalRead(buttonPin) == LOW){
        return true;
    }else{
        return false;
    }
}