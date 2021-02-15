#include <EEPROM.h>
#define FAN 3
#define FS_ADDR 0x01

int fanSpeed ;

int val = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode (3, OUTPUT);
  EEPROM.get(FS_ADDR, fanSpeed);
  if(fanSpeed < 1) fanSpeed = 255;
  analogWrite(FAN, fanSpeed);
  Serial.begin(9600);

}
  char rx_byte = 0;
  String input = "";

void loop() {
   if(Serial.available() > 80){ // check available character
    rx_byte =  Serial.read(); // get the character

    if ((rx_byte >= '0') && (rx_byte <= '9')){
      input.concat(rx_byte); 
    Serial.println(rx_byte);      
    }
    else if(rx_byte == '\n') {
      Serial.print("Received");
      Serial.println(input);
      if(input.toInt() < 256){
        fanSpeed = input.toInt();
        EEPROM.put(FS_ADDR,fanSpeed);
        Serial.print(fanSpeed);
      }else{
        Serial.println("Invalid Number");
      } 
      input = ""; 
    }
    else {
      Serial.println("Not a Number");
    } 
  }
  analogWrite(FAN, fanSpeed);
}
