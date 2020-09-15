/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*NOTES PASTELTECH
*A good option would be storing 10 values, getting the most
*common number in the set and sending that
*/
#include <Servo.h>
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 12;
const int startAngle = 0;
const int endAngle = 180;
int angle = 0;
// defines variables
long duration;
int distance = 0;
Servo servo;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

servo.attach(servoPin);
Serial.begin(9600); // Starts the serial communication

}
void loop() {
   /* THERE IS A PROBLEM HERE, THE CODE FOR THE DISTANCE SENSOR
    *  SEEMS TO MESS UP THE SERVO MOTOR WORKING CORRECTLY NOT SURE THE EXACT REASON WHY
    *  I WILL TRY TO COMMENT OUT THE SERIAL PRINTS AND TRY TO MOVE THOSE TO THE END
    *  More Notes on the top
    *  There seems to be a problem with the HC-SR04 Sensor not returning a value
    *  This causes the whole thread to hang on waiting for the echo pin to return a value
    *  Fixing that and having a hard limit would be a good idea, and also just returning the same value
    *  from the previous accesible echo time would be a good way to go about it. 
     */
     if(angle>endAngle)
  {
    angle = startAngle;
  }
    servo.write(angle);
   
    angle= angle +1;
  
  



  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH,7000);
  // Calculating the distance

  distance= duration*0.034/2;
  if(distance == 0 || distance >99)
  {
    distance = 99;
  }
  // Prints the distance on the Serial Monitor
  //Serial.print("Distance: ");

  
  
  Serial.print(angle);
  Serial.print(" ");
  Serial.println(distance);
  
  
 
    delay(30);
  //will attempt to read it I want it to be able to read every value
  
  

}
