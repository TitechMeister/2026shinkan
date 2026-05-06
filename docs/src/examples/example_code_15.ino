#define D3 analogPin

uint8_t led[3] = {D0,D1,D2};
unsigned long previousTime = 0;
unsigned long currentTime = 0;
long sum = 0;
uint8_t samplecount = 0;

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
    pinMode(analogPin,INPUT);
    Serial.begin(9600);
    previousTime = millis();
}

void loop(){
    currentTime = millis();

    switch(LEDstate){

        case LED1ON:
            digitalWrite(led[0],HIGH);
            if(currentTime - previousTime > 3000){  //ボタンが指から離れた瞬間を捉える
                previousTime = millis();
                LEDstate = Status::LED2ON;
            }
            break;

        case LED2ON:
            digitalWrite(led[1],HIGH);
            if(currentTime - previousTime > 3000){  //ボタンが指から離れた瞬間を捉える
                previousTime = millis();
                LEDstate = Status::LED3ON;
            }
            break;

        case LED3ON:
            digitalWrite(led[0],HIGH);
            if(currentTime - previousTime > 3000){  //ボタンが指から離れた瞬間を捉える
                previousTime = millis();
                LEDstate = Status::LED1ON;
            }
            break;
            
    }

    sum = analogRead(analogPin);
    samplecount ++;

    if(samplecount > 20){
        float cm = ((float)sum / samplecount) * 1.27;
        samplecount = 0;
        Serial.print("Distance :");
        Serial.print(cm);
        Serial.println("cm");
    }
    
}