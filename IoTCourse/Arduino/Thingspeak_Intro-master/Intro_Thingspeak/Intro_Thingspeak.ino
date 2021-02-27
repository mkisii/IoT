
#include <ESP8266WiFi.h>// library to help in communication
#include "DHT.h" // including the Temperature Humidity module
#define DHTTYPE DHT22
#define DHTPIN D7 // defining the NodeMCU 
DHT dht(DHTPIN, DHTTYPE);


String apiKey = "P9TCMHR26IMX4T5F";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "My hotspot";     // replace with your wifi ssid and wpa2 key
const char *pass =  "1234567890"; // wifi Password
const char *server = "api.thingspeak.com";


WiFiClient client;// instance of a connection

void setup()
{
  Serial.begin(115200); // board rate
  dht.begin(); // initializing the DHT module



  Serial.println("Connecting to ");
  Serial.println(ssid);


  WiFi.begin(ssid, pass); // configuration of the board to the wifi 

  while (WiFi.status() != WL_CONNECTED) // checking the connectivity status
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

}

void loop()
{

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  if (client.connect(server, 80))  //   "184.106.153.149" or api.thingspeak.com
  {
    // sending the DHT22 module values temperature and humidity
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(t);
    postStr += "&field2=";
    postStr += String(h);
    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n"); // sending data to thingspeak
    client.print("Host: api.thingspeak.com\n"); // the server host
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" degrees Celcius, Humidity: ");
    Serial.print(h);
    Serial.println("%. Send to Thingspeak.");
  }
  
  //client.stop();

  Serial.println("Waiting...");

  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(20000);
}
