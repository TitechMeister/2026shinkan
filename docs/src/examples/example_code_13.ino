#define ButtonPin D9

uint8_t led[3] = {D0,D1,D2};
unsigned float previousTime = 0;

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

        case LED1ON:
            digitalWrite(led[0],HIGH);
            if(previousButtonState == LOW && digitalRead(ButtonPin) == HIGH){  //ボタンが指から離れた瞬間を捉える
                LEDstate = Status::LED2ON;
            }
            break;

        case LED2ON:
            digitalWrite(led[1],HIGH);
            if(previousButtonState == LOW && digitalRead(ButtonPin) == HIGH){
                LEDstate = Status::LED3ON;
            }
            break;

        case LED3ON:
            digitalWrite(led[0],HIGH);
            if(previousButtonState == LOW && digitalRead(ButtonPin) == HIGH){
                LEDstate = Status::LED1ON;
            }
            break;
            
    }

    previousButtonState = digitalread(ButtonPin);  //この時点でのボタンの状態を保存
    
}