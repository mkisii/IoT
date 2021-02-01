//#include <ThingSpeak.h>

#include <DHTesp.h>
#include "Arduino.h"
//#include <SoftwareSerial.h>

#define DEBUG true

//SoftwareSerial esp8266(9,10); //Rx, Tx -> For the Wi-Fi module
//#include <stdlib.h>
//#define SSID "C89" // "SSID-WiFiname"
//#define PASS "12345678910" // "password"



#include <DHT.h>

#include <LiquidCrystal.h>

#define BACKLIGHT_PIN 3
#define DHTPIN 9
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);


LiquidCrystal lcd (2, 3, 4, 5, 6, 7); //RS, EN ,D4, D5, D6, D7

//Defining varables
int chk;
float hum; // to store humidity value
float temp ;// to store temperature valae


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  dht.begin();
  //  lcd.setBacklight(HIGH);
  //  lcd.setBaclinghtPin(BACKLIGHT_PIN, POSITIVE);


}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3000);

  // reading the dat from the sensor and storing them to its variables
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  //Printing the Temperature and Humidity value to a Serial Monitor

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println(" % ");

  Serial.println("---------");

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" Celsius ");


  // Print the Temp and Hum values to a lcd

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(hum);
  lcd.print("%");

  delay(3000);




}
