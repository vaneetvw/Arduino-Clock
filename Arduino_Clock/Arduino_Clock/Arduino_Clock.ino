/*
Mathis Van Eetvelde 2/6/17
*/



int seconds = 0;
int minutes = 0;
int hours = 0;
int clockOn = 1; //I had to disable the clock to test some things

void setup() {
Serial.begin(9600);
Serial.print("Starting to count!");


}

void loop() {

if(clockOn = 1){
    seconds ++;
} else {

    Serial.print("The clock is disabled, please change clockOn int to 1!");
}



    
}

void checkTime(){
    if(seconds >= 60){
        minutes ++;
        seconds = 0;
        Serial.print("A minute has gone by!");
    }
    
    if(minutes >= 60){
        hours ++;
        minutes = 0;
        Serial.print("An hour has gone by!");
    }
}
