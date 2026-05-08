#define analogPin D3

uint8_t led[3] = {D0,D1,D2};
unsigned long previousTime = 0;
unsigned long currentTime = 0;
unsigned long sum = 0;
uint8_t samplecount = 0;

enum class Status {
    LED1ON,
    LED2ON,
    LED3ON
};

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

        case Status::LED1ON:
            digitalWrite(led[0],HIGH);
            if(currentTime - previousTime > 3000){  
                previousTime = millis();
                LEDstate = Status::LED2ON;
            }
            break;

        case Status::LED2ON:
            digitalWrite(led[1],HIGH);
            if(currentTime - previousTime > 3000){  
                previousTime = millis();
                LEDstate = Status::LED3ON;
            }
            break;

        case Status::LED3ON:
            digitalWrite(led[2],HIGH);
            digitalWrite(led[0],LOW);
            digitalWrite(led[1],LOW);
            if(currentTime - previousTime > 3000){  
                previousTime = millis();
                LEDstate = Status::LED1ON;
            }
            break;
            
    }

    sum += analogRead(analogPin);
    samplecount ++;

    if(samplecount > 20){
        float cm = ((float)sum / samplecount) * 1.27;
        samplecount = 0;
        sum = 0;
        Serial.print("Distance :");
        Serial.print(cm);
        Serial.println("cm");
    }
    
}