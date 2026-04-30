#define D9 button
uint8_t led[3] = {D0,D1,D2};

void setup(){
    for(uint8_t i = 0; i < 3; i++){
        pinMode(led[i],OUTPUT);
    }
    pinMode(button,INPUT);
}

void loop(){
    if(digitalRead(button) == LOW){
        for(uint8_t i = 0; i < 3; i++){
        digitalWrite(led[i],HIGH);
        delay(500);
    }
    }else{
        for(uint8_t i = 0; i < 3; i++){
        digitalWrite(led[i],LOW);
    }
}