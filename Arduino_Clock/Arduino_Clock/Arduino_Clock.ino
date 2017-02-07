/*
Mathis Van Eetvelde 2/6/17
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//Sun & Moon Characters
byte day[8] = {
  0b00100,
  0b10001,
  0b01110,
  0b11111,
  0b01110,
  0b10001,
  0b00100,
  0b00000
};
byte night[8] = {
  0b00111,
  0b01110,
  0b01100,
  0b01100,
  0b01100,
  0b01110,
  0b00111,
  0b00000
};

int isDay = 1;


  
int seconds = 0;
int minutes = 0;
int hours = 2;
int clockOn = 1; //I had to disable the clock to test some things



void setup() {

  
Serial.begin(9600);
Serial.print("Starting to count!");
lcd.begin(16, 2);
lcd.createChar(1, day);
lcd.createChar(2, night);

}

void loop() {
Serial.print(isDay);
if(clockOn = 1){
    seconds ++;
    checkTime();
    printTime();
    preTime();
    delay(1000);
    lcd.clear();

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

    if(hours >= 6 || hours <= 19){
      isDay = 1;
      }else{isDay = 0;}
}
void printTime(){
    lcd.setCursor(0,1);
    lcd.print(hours);
    lcd.setCursor(2,1);
    lcd.print(":");
    lcd.setCursor(4,1);
    lcd.print(minutes);
    lcd.setCursor(6,1);
    lcd.print(":");
    lcd.setCursor(8,1);
    lcd.print(seconds);
}
void preTime(){
  lcd.setCursor(0,0);
  lcd.print("The Time Is:");
  lcd.setCursor(11,1);
  lcd.print("D/N:");
  if(day == 1){
    lcd.setCursor(15,1);
    lcd.write(1);
    }else{
        lcd.setCursor(15,1);
        lcd.write(2);
      
      }


    
  
  }
