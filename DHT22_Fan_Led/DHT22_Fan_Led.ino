
/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
*/

//Libraries
#include <DHT.h>

//Constants
#define DHTPIN 9     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables

float hum;  //Stores humidity value
float temp; //Stores temperature value
int fan = 10;// Stores the values
int led = 13;



void setup()
{
  // defing the value
  Serial.begin(9600);
  dht.begin();
  pinMode(fan,OUTPUT);
  pinMode(led,OUTPUT);
 
}

void loop()
{
    delay(2000);
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
  
    
    
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.println(" %");
    Serial.print("Temperature: ");// Reading the temperature values
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(1000); //Delay 2 sec.

    if ((temp > 20) && (hum > 30)){// Executing logic function
      digitalWrite(fan, HIGH); // Making the fan On
      digitalWrite(led, HIGH);// making the Led On
    }else{
      digitalWrite(fan,LOW);// Fan is OFF
      digitalWrite(led, LOW);// LED id OFF
    }
}
