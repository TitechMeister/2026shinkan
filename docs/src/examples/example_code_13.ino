#define ButtonPin D9

uint8_t led[3] = {D0,D1,D2};
unsigned long previousTime = 0;

enum class Status {
    LED1ON,
    LED2ON,
    LED3ON
};

bool previousButtonState = HIGH;

Status LEDstate = Status::LED1ON;

void setup(){

    for(uint8_t i = 0; i < 3; i ++){
        pinMode(led[i],OUTPUT);
    }
    pinMode(ButtonPin,INPUT);
    Serial.begin(9600);
    previousTime = millis();
}

void loop(){

    switch(LEDstate){

        case Status::LED1ON:
            digitalWrite(led[0],HIGH);
            digitalWrite(led[1],LOW);
            digitalWrite(led[2],LOW);
            if(previousButtonState == LOW && digitalRead(ButtonPin) == HIGH){  //ボタンが指から離れた瞬間を捉える
                LEDstate = Status::LED2ON;
            }
            break;

        case Status::LED2ON:
            digitalWrite(led[1],HIGH);
            digitalWrite(led[0],LOW);
            digitalWrite(led[2],LOW);
            if(previousButtonState == LOW && digitalRead(ButtonPin) == HIGH){
                LEDstate = Status::LED3ON;
            }
            break;

        case Status::LED3ON:
            digitalWrite(led[2],HIGH);
            digitalWrite(led[0],LOW);
            digitalWrite(led[1],LOW);
            if(previousButtonState == LOW && digitalRead(ButtonPin) == HIGH){
                LEDstate = Status::LED1ON;
            }
            break;
            
    }

    previousButtonState = digitalRead(ButtonPin);  //この時点でのボタンの状態を保存
    
}