int pinled1 = 13;
int pinled2 = 12;
int counter  ;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinled1,OUTPUT);
  pinMode(pinled2,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(pinled1,HIGH);
  if (pinled1 % 2 == 1){
         // LED ON  high level of voltage supply
        Serial.println("Led 1 is ON");
        digitalWrite(pinled2,LOW); // LED OFF low level of voltages
        Serial.println("Led 2 is OFF");
        delay(1000); // delay for a second
          
  }
  if (pinled2 % 2 == 0){
        Serial.println("-------");
        digitalWrite(pinled2,HIGH);
       Serial.println("Led 2 is ON");
        digitalWrite(pinled1,LOW);
        Serial.println("Led 1 is OFF");
      
        delay(1000);
          
  }
  counter = counter + 1;
  Serial.println(counter);

  


}
