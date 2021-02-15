#define DEBUG true
#include <SoftwareSerial.h>
SoftwareSerial esp8266(9,10);
//
//#define SSID "TUK-WIFI"
//#define PASS "P@ssword@123"
//void setup(){
//  Serial.begin(9600);




//  esp8266.begin(115200);
//  
//  esp8266.println("AT");
// delay(5000);
//
//
//   }
//
//void loop(){
//   if (esp8266.find("OK")){
//  esp8266.println("Wifi found");
// }else{
//  esp8266.println("Wifi not found");
// }
//  
//}
#include <SPI.h>
#include <WiFi.h>

char ssid[] = "TUK-WIFI";  // the name of your network

void setup() {
  Serial.begin(9600);

  int status = WiFi.begin(ssid);

  if (status != WL_CONNECTED) {
    Serial.println("Couldn't get a WiFi connection");
    while (true);
  }
  else {
    // if you are connected, scan for available WiFi networks and print the number discovered:
    Serial.println("** Scan Networks **");
    byte numSsid = WiFi.scanNetworks();

    Serial.print("Number of available WiFi networks discovered:");
    Serial.println(numSsid);
  }
}

void loop() {}
