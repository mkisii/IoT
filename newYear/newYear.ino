#include <LiquidCrystal.h>

LiquidCrystal lcd (2,3,4,5,6,7);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);


}

void loop() {
  // put your main code here, to run repeatedly:
int a = 2020;


//lcd.setCursor(0,0);
////Serial.println("Bye 2020");
//lcd.print("Hello 2020");


//Serial.println("Hello Guys Wellcome to 20217 :");
lcd.setCursor(0,0);
lcd.print("Happy New Year ");
lcd.setCursor(1,7);
lcd.print(2021);
}
