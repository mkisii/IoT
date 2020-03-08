#include <SD.h>
#include <SPI.h>

File myFile;

int pinCS = 4; // pin 11 on arduino uno

/*


  sd card reader
  ************** 
  cs to pin 4
  mosi to pin 11
  sck to pin 13
  miso to pin 12

  finger print module
  *******************
  Green - ground
  black - vcc
  Yellow - rx
  white - tx

*/


void setup() {
  Serial.begin(9600);
  pinMode(pinCS, OUTPUT);

  //SD card Initialization
  if (SD.begin() )
  {
    Serial.println("SD card is read to use");
  }else
  {
    Serial.println("SD card inilialization failed");
    return;
  }
  
  /* myFile = SD.open("new.csv", FILE_WRITE);
   if(myFile) {
     myFile.println("1,2,3,4");
     myFile.close();

     Serial.println("Done writing ..");
   }
   
   else{
    
      Serial.println("error opening new.txt"); 
      
   }*/

   myFile = SD.open("new.csv");
   if (myFile) {
    Serial.println("Read:");
    String line_data;
    while (myFile.available()) {
      char data = myFile.read();
      line_data+=data;

      if(data == '\r'){
        int startIndex = 0;
        int firstComma = line_data.indexOf(',', startIndex+1);
        int secondComma = line_data.indexOf(',', firstComma+1);
        int thirdComma = line_data.indexOf(',', secondComma+1);
        String id = line_data.substring(startIndex, firstComma);
        String studentName = line_data.substring(firstComma, secondComma);
        String registration = line_data.substring(secondComma, thirdComma);
        Serial.print("\n name: ");
        Serial.print(studentName);
        Serial.print(" Registration: ");
        Serial.print(registration);
        Serial.print(" ID: ");
        Serial.println(id);
        
        Serial.println(line_data);
        line_data = "";
        //break;
      }
     
      
   }
   
    myFile.close();
   }
   else {
    Serial.println("Error opening new.txt");
   }

  

}

void loop() {
  // put your main code here, to run repeatedly:

}
