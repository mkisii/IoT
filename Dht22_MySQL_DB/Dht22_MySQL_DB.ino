
#include<DHT.h>
#include<SPI.h>
#define DHTPIN 3
#define DHTTYPE  DHT22
DHT dht(DHTPIN, DHTTYPE)

float Humidity;
float Temperature;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin()

}

void loop() {
  // put your main code here, to run repeatedly:
  Humidity = dht.readHumidity();
  Temperature = dht.readTemperature();
  Sending_Data_To_MySQLDatabase();
  delay()
}

void Sending_Data_To_MySQLDatabase(){
  
}
