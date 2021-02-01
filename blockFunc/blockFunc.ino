
int led = 13; // defining the output pin number

bool myLed = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  bool ledState;
  
  Serial.println("Led is ON");
  delay(1000);

  digitalWrite(led,LOW);
  Serial.println("Led is OFF");
  delay(1000);
  

}
