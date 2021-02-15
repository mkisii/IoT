float sinVal;
int toneVal;
int val = 0;
int led = 13;
void setup() {
  // put your setup code here, to run once:

  pinMode(8, OUTPUT);//define the pin number
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(0);

  if(val<1000){
    Serial.println(val);
    digitalWrite(led,HIGH);
      for(int x=0;x<180;x++){ //values that varries from 0 to 180
    
    sinVal = (sin(x*(3.1412/180))); //Computing the sinVal
    
    toneVal = 2000+(int(sinVal*1000)); // adding the toneVal and sinVal
    
    tone(8,toneVal);// writing the output value to the arduio board
    delay(2);
  }
  
  }else{
    digitalWrite(led,LOW);
    noTone(8);
    Serial.println(val)
    
  }
    
   



}
