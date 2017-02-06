/*
Mathis Van Eetvelde 2/6/17
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


int seconds = 0;
int minutes = 0;
int hours = 0;
int clockOn = 1; //I had to disable the clock to test some things

void setup() {
Serial.begin(9600);
Serial.print("Starting to count!");
lcd.begin(16, 2);
lcd.setCursor(0,0);

}

void loop() {

if(clockOn = 1){
    seconds ++;
    checkTime();
    printTime();
    delayMicroseconds(1000);
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
void printTime(){
    lcd.setCursor(0,1);
    lcd.print(hours);
    lcd.setCursor(2,1);
    lcd.print(":");
    lcd.setCursor(4,1);
    lcd.print(minutes);
    lcd.setCursor(6,1);
    lcd.print(seconds);
}
