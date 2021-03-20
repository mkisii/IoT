float sinVal;
int toneVal;
int led;

unsigned long temTimer;
void setup() {
  // put your setup code here, to run once:

  pinMode(8, OUTPUT);//define the pin number
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int val;
  double data;
  val = analogRead(0);
  data = (double)val*(5/10.24); // convert voltage to temperature

  if (data >25){

      for(int x=0;x<180;x++){ //values that varries from 0 to 180
    
    sinVal = (sin(x*(3.1412/180))); //Computing the sinVal
    
    toneVal = 2000+(int(sinVal*1000)); // adding the toneVal and sinVal
    
    tone(8,toneVal);// writing the output value to the arduio board
    delay(2);
  }

    
  }else{
    digitalWrite(led,LOW);
    noTone(8);
  }
  //every 500 millis
  if (millis()- temTimer > 50){
    temTimer = millis();
    Serial.println("Temperature");
    Serial.println(data);
    Serial.println("C");
  }



}
