#define button D9
const uint8_t led[3] = {D0,D1,D2};
volatile uint8_t Button_State = 0

void setup(){
    for(uint8_t i = 0; i < 3; i ++){
        pinMode(led[i],OUTPUT);
    }
    pinMode(button,INPUT);
    attachInterrupt(digitalPinToInterrupt(button), buttonISR, FALLING);
}

void loop(){
    switch(Button_State){
        case 0:
            for(uint8_t i = 0; i < 3; i ++){
                digitalWrite(led[i],HIGH);
            }
            break;

        case 1:
            for(uint8_t i = 0; i < 3; i ++){
            digitalWrite(led[i],HIGH);
            }
            delay(500);
            for(uint8_t i = 0; i < 3; i ++){
            digitalWrite(led[i],LOW);
            }
            break;
        
        case 2:
            for(uint8_t i = 0; i < 3; i ++){
                LED_onoff(led[i];500);
            }
            break;

    }
}

void LED_onoff(uint8_t LEDPin, unsigned long delayTime){
    digitalWrite(LEDPin,HIGH);
    delay(delayTime);
    digitalWrite(LEDPin,LOW);
    delay(delayTime);
}

void buttonISR(){
    Button_State = (Button_State + 1) % 3;
}