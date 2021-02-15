float sinVal;
int toneVal;
void setup() {
  // put your setup code here, to run once:

  pinMode(8, OUTPUT);//define the pin number

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int x=0;x<180;x++){ //values that varries 
    
    sinVal = (sin(x*(3.1412/180))); 
    
    toneVal = 2000+(int(sinVal*1000)); // adding the toneVal and sinVal
    
    tone(8,toneVal);// writing the output value to the arduio board
    delay(2);
  }

}
