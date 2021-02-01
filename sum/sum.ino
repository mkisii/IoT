#include <Keyboard.h>

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

int a = 8 ;
int b= 6;
int d;
int c;
int SetSumTo = 15;
int sum = 0;
int x = sum + a + b;
Serial.println(x);
if (SetSumTo !=x){
  d = SetSumTo + x;
  
}
else{
  c = SetSumTo * x ;
}
Serial.println(d);
Serial.println(c);

delay(2000);
}
