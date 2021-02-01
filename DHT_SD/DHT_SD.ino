#include <SD.h>

#include <DHT.h>
#include <SD.h>
#include <SPI.h>

uint8_t DHTPin= 9;
//#define DHTPin  9
#define DHTTYPE DHT22
DHT dht(DHTPin, DHTTYPE);

float Temperature;
float Humidity;
const int chipSelect = 10; // 
File dataFile;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DHTPin, INPUT);
  dht.begin();
  Initialize_SDcard();

}

void loop() {
  // put your main code here, to run repeatedly:
  Write_SDcard();
  Read_TempHum();
  delay(5000); //Wait for 5 seconds
//  Temperature = dht.readTemperature();
//  Humidity = dht.readHumidity();
//  Serial.println(Temperature);
//  Serial.println(Humidity);

}

void Read_TempHum(){
  Temperature = dht.readTemperature();
  Humidity = dht.readHumidity();
  Serial.println(Temperature);
  Serial.println(Humidity);
}

void Initialize_SDcard()
{
  if(!SD.begin(chipSelect))
  {
    Serial.println("SD failed, or not present");
    return;
  }
  File dataFile = SD.open("LoggerCD.txt", FILE_WRITE);
  if (dataFile)
  {
   dataFile.println("Temperature,Humidity"); // Write the first row of the axcel file
   dataFile.close();
  }
}
void Write_SDcard(){
  File dataFile = SD.open("LoggerCD.txt", FILE_WRITE);
  if (dataFile)
  {
    dataFile.print(Temperature); // Store Temperature on SD card
    dataFile.print(","); // Move to next column seperated by ","
    dataFile.print(Humidity); // Storre Humidity to SD card
    dataFile.print(","); // Move to next column separated by a "'"
    dataFile.println(); // Move to next row
    dataFile.close(); //close the file 
    
  }
  else
  Serial.println("SD card writing failed");
  
}
