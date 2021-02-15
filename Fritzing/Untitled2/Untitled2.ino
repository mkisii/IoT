// PROJECT 3 Interactive Traffic Light
//Light configuration

int carRed = 13;
int carYellow = 12;
int carGreen = 11;
int pedRed = 10;
int pedGreen = 9;

//configure button as input
int button = 8;

int crossTime = 2000;
long changeTime;//time for pedestrians to pass unsigned

//time that the button is pressed
void setup() {
//configure all LEDs as output
pinMode(carRed, OUTPUT);
pinMode(carYellow, OUTPUT);
pinMode(carGreen, OUTPUT);
pinMode(pedRed, OUTPUT);
pinMode(pedGreen, OUTPUT);
pinMode(button, INPUT);

digitalWrite(carGreen, HIGH); //initialize green traffic light on
digitalWrite(pedRed, HIGH); //initialize red pedestrian light off
digitalWrite(carRed, LOW);
digitalWrite(carYellow, LOW);
digitalWrite(pedGreen, LOW);

Serial.begin(9600);
}

void loop() {
  //defining the button value when pressed
int state = digitalRead(button);
Serial.println(state);
// test if the button is pressed and if 5 seconds have passed after it is pressed lately.

if(state == HIGH && (millis() - changeTime)> 5000){
  changeLights();
  }
//carry out the function of changing LED

}

void changeLights() {
  digitalWrite(carGreen, LOW); //green traffic light off
  digitalWrite(carYellow, HIGH); //yellow traffic light on
  delay(2000);
  
  //wait for 2 secs
  digitalWrite(carYellow, LOW); // yellow traffic light off
  digitalWrite(carRed, HIGH);
  //red traffic light on
  delay(1000); // wait for 1 sec for safety reason

  
  digitalWrite(pedRed, LOW);//red pedestrian light off
  digitalWrite(pedGreen, HIGH); //light pedestrian light on
  delay(crossTime);
  
  //blink green pedestrian light to notify pedestrians to pass soon
  for (int x=0; x<10; x++) {
    
    digitalWrite(pedGreen, HIGH);
    delay(150);
    digitalWrite(pedGreen, LOW);
    delay(150);
//    digitalWrite(carYellow,HIGH);
//    delay(100);
  }
  digitalWrite(pedGreen, LOW);
  digitalWrite(carRed,LOW);
  digitalWrite(pedRed, HIGH);
  digitalWrite(carGreen, HIGH);

  changeTime = millis();
  // record the duration since last change

  //back to the loop of main code
}
