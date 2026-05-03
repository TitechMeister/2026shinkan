
void setup(){
    Serial.begin(9600);
    Serial1.begin(9600);
}

void loop(){

    int SonicData[5] = {0,0,0,0,0};

    if(Serial1.available()){
        SonicData[0] = Serial1.read();
        if(SonicData[0] == 'R'){

            while(!Serial1.available());

            SonicData[1] = Serial1.read();
        }
        while(!Serial1.available());//上一桁以外のデータを破棄
        SonicData[2] = Serial1.read();
        while(!Serial1.available());
        SonicData[3] = Serial1.read();
        while(!Serial1.available());
        SonicData[4] = Serial1.read();

    }

    int inches = SonicData[1] - '0';

    Serial.println(inches);


}