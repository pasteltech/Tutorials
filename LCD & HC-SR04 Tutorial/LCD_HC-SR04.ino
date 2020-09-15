#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define trigPin 13
#define echoPin 12
#include <elapsedMillis.h>




LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity
elapsedMillis timer0;
void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  
 
}
void loop()
{
  
 // lcd.print("hello son");
   long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
    if(distance < 200)
    {
    lcd.print(distance);
    lcd.print(" cm ");
    }
  delay(1000);
  lcd.clear();
  
  //lcd.clear();
  
  //delay(1000);
  //lcd.print("Hello Worldkl;kljklj"); 
  //delay(1000);
 // lcd.clear();
  
}

