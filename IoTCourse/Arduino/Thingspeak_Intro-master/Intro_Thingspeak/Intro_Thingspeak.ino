
#include <ESP8266WiFi.h>// library to help in communication

String apiKey = "P9TCMHR26IMX4T5F";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "My hotspot";     // replace with your wifi ssid and wpa2 key
const char *pass =  "1234567890";
const char *server = "api.thingspeak.com";


WiFiClient client;// instance of a connection

void setup()
{
  Serial.begin(115200); // board rate



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

  float h = 65;
  float t = 30;



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
