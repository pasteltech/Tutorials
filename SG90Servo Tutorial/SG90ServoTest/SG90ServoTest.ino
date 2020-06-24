#include <Servo.h>

/*
Into Robotics
*/
 

 
int servoPin = 12;
 
Servo servo;  
 
int servoAngle = 0;   // servo position in degrees
int store = 0;
int start = 0;
int end = 180;
bool isEnd = false;
void setup()
{
  Serial.begin(9600);  
  servo.attach(servoPin);
}
 
 
void loop()
{
//control the servo's direction and the position of the motor
    store = millis();
    Serial.println("hello world");
    Serial.println("Servo started off at" + servo.read());
    
    //servo.writeMicroseconds(2000);
    Serial.println("Servo is fully ClockWise: Rotation = " + servo.read());
   // Serial.println
    for(int i = 15; i < 165; i++)
    {
      servo.write(i);
      delay(15);
    }
    for(int i = 165; i >=15; i--)
    {
        servo.write(i);
        delay(15);
    }
    Serial.println("Servo is fully ClockWise: Rotation = " + servo.read());
  //  servo.writeMicroseconds(2000);
    Serial.println("Millies ellapsed = " + millis()-store);
    /*
    for(int i = 176; i >4; i--)
    {
      servo.write(i);
      delay(30);
    }
    */
//end control the servo's direction and the position of the motor



}
