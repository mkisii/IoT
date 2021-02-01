#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);//RS, E, D4, D5,D6,D7


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Acolumn,Bcolumn, Ccolumn, Dcolumn");
  Serial.println("RESETTIMER");
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorValue = analogue(A0);
  Serial.print("DATA, TIME. TIMER, DATE");
  Serial.println(sensorValue);
  delay(3000);

}
