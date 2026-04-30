
const uint8_t led[3] = {D0 ,D1 ,D2};

void setup(){
    for(uint8_t i = 0; i < 3; i++){
        pinMode(led[i],OUTPUT);
    }
}

void loop(){
    digitalWrite(led[0],HIGH);
    delay(1000);
    digitalWrite(led[0],LOW);
    digitalWrite(led[1],HIGH);
    delay(1000);
    digitalWrite(led[1],LOW);
    digitalWrite(led[2],HIGH);
    delay(1000);
    digitalWrite(led[2],LOW);
}