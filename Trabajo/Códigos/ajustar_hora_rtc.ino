#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  DateTime ahora = rtc.now();

  if (ahora.day() < 10) Serial.print('0');
  Serial.print(ahora.day());     
  Serial.print('/');
  if (ahora.month() < 10) 
  Serial.print('0');
  Serial.print(ahora.month());   
  Serial.print('/');
  Serial.print(ahora.year());    
  Serial.print("  ");

  if (ahora.hour() < 10) Serial.print('0');
  Serial.print(ahora.hour());    
  Serial.print(':');
  if (ahora.minute() < 10) Serial.print('0');
  Serial.print(ahora.minute());  
  Serial.print(':');
  if (ahora.second() < 10) Serial.print('0');
  Serial.println(ahora.second());

  delay(1000);
}
