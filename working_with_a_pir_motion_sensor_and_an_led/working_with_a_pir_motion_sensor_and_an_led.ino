//defining the variables we are going to use
int led = 13;
int sensor =2;
int state = LOW;
int val = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(sensor);

  if (val == HIGH) {
    digitalWrite(led, HIGH);
    delay(100); //delay set to 100 milliseconds

    if (state == LOW) {
      Serial.println("Motion detected!");
      state = HIGH; //Update the variable state to high
    }
  }

  else {
    digitalWrite(led, LOW); //Turns off the led
    delay(2000); //delay set to 2000 milliseconds

    if (state == HIGH){
      Serial.println("Motion stopped!");
      state = LOW; //update variable state to low

    ++++++++++}
    }
  }
