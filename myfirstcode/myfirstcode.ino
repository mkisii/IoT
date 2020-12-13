#include <LiquidCrystal.h>



LiquidCrystal lcd (2, 3, 4, 5, 6, 7); //RS, E,D4, D5, D6, D7
// A to VDD, K to GND
void setup(){

  lcd.begin(16,2);
  
}
  

void loop() {
  // put your code here, to run repeatedly:

  //clearing the lcd secreen
  lcd.clear();

   // setting the cursor start position
  lcd.setCursor(0,0);

  delay(3000);
  
  //The blink function to
  lcd.blink();
  
  // print a message to lcd
  lcd.println("Welcome to IoT");

  // Setting the delay time
  delay(3000);
  lcd.noBlink();



  

  

 
  
 
}
