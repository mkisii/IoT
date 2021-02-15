int led = 13;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(0);
  Serial.println(val);
  if(val <1000){
    digitalWrite(led,LOW);
    
  }else{
    digitalWrite(led, HIGH);
  }
delay (10);
}
