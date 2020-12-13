#include <LiquidCrystal.h>

LiquidCrystal lcd (2, 3, 4, 5, 6, 7);// RS, E, D4, D5, D6, D7 AND A to VCC, K to GND


int led = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  lcd.begin(16,2);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  
  lcd.setCursor(1,0);
  digitalWrite(led, HIGH);
  lcd.print("The LED is ON");
  delay(3000);


  lcd.clear();
  digitalWrite(led, LOW);
  lcd.print("The LED is OFF");
  delay(3000);

}
