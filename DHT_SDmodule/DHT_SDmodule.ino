#include <SPI.h>
#include <SD.h>
#include <DHT.h>

//defining the DHT22 pin number

#define DHTPIN 7
#define DHTTYPE DHT22


DHT dht(DHTTYPE, DHTPIN);
float t;
float h;

const int chipselect = 4;

//Creating a file to store Temp and Humidity data
File myFile;

void setup() {
  
  // initializing the DHT22 module
  dht.begin();
  // initializing the Serial
  Serial.begin(9600);

  //setting up the SD card
  //Serial.println("Initialization!");

  if(!SD.begin(chipselect)){
    Serial.println("SD Initialization failed");
    return;
  }
  Serial.println("Initialization done");

 //opening file
 myFile = SD.open("DATA.txt", FILE_WRITE);

 //if file is opened then write to it
  if(myFile){
    Serial.println("File Opened ready to write");
    myFile.println("Temperature C, Humidity %");
}
myFile.close();
}
void loggingTemperatureAndHumidity(){
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Serial.print(t);
  if (isnan(t)){
    Serial.println("Failed to read Values From DHT sensor");
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C");
  Serial.println("-------");

  Serial.print("Humidity: ");
  Serial.print(t);
  Serial.print(" %");
  Serial.print("------");

  myFile = SD.open("DATA.txt", FILE_WRITE);
  if (myFile) {
    Serial.println("open with Success ");
    myFile.print(t);
    myFile.println(",");
  }
  myFile.close();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  loggingTemperatureAndHumidity();
  delay(5000);

}
