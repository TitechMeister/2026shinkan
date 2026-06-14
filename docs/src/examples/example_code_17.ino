#define analog_Pin D3
#define PWM_Pin D8

class SensorCalcu{
    private:
        uint8_t Pin;
        unsigned long add = 0;
        uint8_t validTime = 0;
        float avg = 0;
        float result = 0;

    public:
        SensorCalcu(uint8_t PinNumber){
            Pin = PinNumber;
            pinMode(Pin,INPUT);
        }

        float pulseCalcu(uint8_t count){
            for(uint8_t i = 0; i < count; i ++){
                add += pulseIn(Pin,HIGH);
                validTime ++;
                delay(50);
            }

            avg = (float)add / validTime;

            return avg;
        }

        float analogCalcu(uint8_t count){
            for(uint8_t i = 0; i < count; i ++){
                add += analogRead(Pin);
                validTime ++;
                delay(50);
            }

            avg = (float)add / validTime;
    
            return avg;
        }

        void reset(){
            add = 0;
            validTime = 0;
            avg = 0;
            result = 0;
        }
};

SensorCalcu analogDistance(analog_Pin);
SensorCalcu PWMDistance(PWM_Pin);

void setup(){
    Serial.begin(9600);
}

void loop(){

    float analogresult = (analogDistance.analogCalcu(10) / 147.0) * 2.54;
    float PWMresult = PWMDistance.pulseCalcu(10) * 1.27;

    Serial.print("analogDistance :");
    Serial.println(analogresult);
    Serial.print("PWMDistance :");
    Serial.println(PWMresult);

    analogDistance.reset();
    PWMDistance.reset();
}
