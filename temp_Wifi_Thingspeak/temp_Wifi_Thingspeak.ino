#include <stdlib.h>

#include <DHT.h>

#define DHTPIN 5         // DHT data pin connected to Arduino pin 5

#define DHTTYPE DHT11     // DHT11 (DHT Sensor Type )

DHT dht(DHTPIN, DHTTYPE); // Initialize the DHT sensor

#define SSID "ur wifi name"     // "WiFi Name"

#define PASS "ur wifi password"       // "Password"

#define IP "184.106.153.149"// thingspeak.com ip

String msg = "GET /update?key=ur api key"; //change it with your key...

float temp;

int hum;

String tempC;

int error;

void setup()

{

  Serial.begin(115200); // use default 115200.

  Serial.println("AT");

  delay(5000);

  if(Serial.find("OK")){

    connectWiFi();

  }

}

void loop(){

   start: 

  error=0;

  temp = dht.readTemperature();

  hum = dht.readHumidity();

  char buffer[10];

  tempC = dtostrf(temp, 4, 1, buffer);

  updateTemp();

  if (error==1){

    goto start;

  }

 

  delay(5000);

}

void updateTemp(){

  String cmd = "AT+CIPSTART=\"TCP\",\"";

  cmd += IP;

  cmd += "\",80";

  Serial.println(cmd);

  delay(2000);

  if(Serial.find("Error")){

    return;

  }

  cmd = msg ;

  cmd += "&field1=";  

  cmd += tempC;

  cmd += "&field2="; 

  cmd += String(hum);

  cmd += "\r\n";

  Serial.print("AT+CIPSEND=");

  Serial.println(cmd.length());

  if(Serial.find(">")){

    Serial.print(cmd);

  }

  else{

    Serial.println("AT+CIPCLOSE");

    //Resend...

    error=1;

  }

}

  boolean connectWiFi(){

  Serial.println("AT+CWMODE=1");

  delay(2000);

  String cmd="AT+CWJAP=\"";

  cmd+=SSID;

  cmd+="\",\"";

  cmd+=PASS;

  cmd+="\"";

  Serial.println(cmd);

  delay(5000);

  if(Serial.find("OK")){

    return true;

  }else{

    return false;

  }

}
