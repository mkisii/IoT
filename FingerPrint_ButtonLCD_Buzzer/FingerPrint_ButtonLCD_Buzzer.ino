#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
#include <SoftwareSerial.h>
SoftwareSerial fingerPrint(2, 3);

#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;

#include "Adafruit_Fingerprint.h"
uint8_t id;
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&fingerPrint);

#define enroll 14
#define del 15
#define up 16
#define down 17
#define match 5
#define indFinger 7
#define buzzer 5

#define records 4  // 5 for 5 user

int user1,user2,user3,user4,user5;
void setup()
{
    delay(1000);
    lcd.begin(16,2);
    Serial.begin(9600);
    pinMode(enroll, INPUT_PULLUP);
    pinMode(up, INPUT_PULLUP);
    pinMode(down, INPUT_PULLUP);
    pinMode(del, INPUT_PULLUP);
    pinMode(match, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
    pinMode(indFinger, OUTPUT);
    digitalWrite(buzzer, LOW);
    if(digitalRead(enroll) == 0)
    {
            digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      lcd.clear();
      lcd.print("Please wait");
      lcd.setCursor(0,1);
      lcd.print("Downloding Data");

      Serial.println("Please wait");
      Serial.println("Downloding Data..");
      Serial.println();

      Serial.print("S.No.         ");
      for(int i=0;i<records;i++)
      {
              digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
        Serial.print("         User ID");
        Serial.print(i+1);
        Serial.print("                   ");
      }
      Serial.println();
      int eepIndex=0;
      for(int i=0;i<30;i++)
      {
        if(i+1<10)
        Serial.print('0');
        Serial.print(i+1);
        Serial.print("          ");
        eepIndex=(i*7);
        download(eepIndex);
        eepIndex=(i*7)+210;
        download(eepIndex);
        eepIndex=(i*7)+420;
        download(eepIndex);
        eepIndex=(i*7)+630;
        download(eepIndex);
      //  eepIndex=(i*7)+840;   // 5th user
      //  download(eepIndex);
        Serial.println();
      }
    }
    if(digitalRead(del) == 0)
    {
      lcd.clear();
      lcd.print("Please Wait");
      lcd.setCursor(0,1);
      lcd.print("Reseting.....");
      for(int i=1000;i<1005;i++)
      EEPROM.write(i,0);
      for(int i=0;i<841;i++)
      EEPROM.write(i, 0xff);
      lcd.clear();
      lcd.print("System Reset");
      delay(1000);
    }

    
    lcd.clear();
    lcd.print("   Attendance   ");
    lcd.setCursor(0,1);
    lcd.print("     System     ");
    delay(2000);
    lcd.clear();
    lcd.print("Circuit Digest");
    lcd.setCursor(0,1);
    lcd.print("Saddam Khan");
    delay(2000);
          digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
  for(int i=1000;i<1000+records;i++)
  {
    if(EEPROM.read(i) == 0xff)
        EEPROM.write(i,0);
   }

    finger.begin(57600);
    Serial.begin(9600);
    lcd.clear();
    lcd.print("Finding Module");
    lcd.setCursor(0,1);
    delay(1000);
    if (finger.verifyPassword())
    {
      Serial.println("Found fingerprint sensor!");
      lcd.clear();
      lcd.print("Found Module ");
      delay(1000);
    }
    else
    {
    Serial.println("Did not find fingerprint sensor :(");
    lcd.clear();
    lcd.print("module not Found");
    lcd.setCursor(0,1);
    lcd.print("Check Connections");
    while (1);
    }

     if (! rtc.begin())
       Serial.println("Couldn't find RTC");

    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

    if (! rtc.isrunning())
    {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
       rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    }
lcd.setCursor(0,0);
 lcd.print("Press Match to ");
 lcd.setCursor(0,1);
 lcd.print("Start System");
 delay(2000);

    lcd.clear();
    digitalWrite(indFinger, HIGH);
    
 }

void loop() {
  // put your main code here, to run repeatedly:

}
