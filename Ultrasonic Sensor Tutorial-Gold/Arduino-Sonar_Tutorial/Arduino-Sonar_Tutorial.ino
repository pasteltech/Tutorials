/*
  Created by Jose 
*/
#include <Servo.h> //This is including a library that is built into the Arduino Code


//These are the pins for the Distance Sensor
const int trigPin = 9;
const int echoPin = 10;

//This is the pin for the SG-90 Servo
const int servoPin = 12;

//Here we have a startAngle of Zero for the Servo, and an endAngle of 180 degrees
const int startAngle = 0;
const int endAngle = 180;

//This stores the current angle
int angle = 0;  

long duration;
int distance = 0;

//Name of our servo
Servo servo;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  servo.attach(servoPin); //attaches servo pin
  Serial.begin(9600); // Starts the serial communication, ctrl+shift+m to start serial monitor!

}
void loop() {

  if (angle > endAngle)
  {
    angle = startAngle; //This sets the angle of the servo to 0 when it reaches 180 degrees. So it can sweep!
    delay(100);
  }
  servo.write(angle);

  angle = angle + 1; //Adds one degree on each loop

  // Clears trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH, 7000); // do not change this delay, this is a timeout feature, otherwise pulseIn could wait for a response for up to a full seconds, will cause jittery movements. 

  // Calculating the distance
  distance = duration * 0.034 / 2;
  if (distance == 0 || distance > 99)
  {
    distance = 100; //here we set 100cm as the max distance we can accurately measure
  }
  

  //Here we print the distance to the serial monitor
  //Some notes on the serial monitor, make sure the baud raud setting is the
  Serial.print(angle);
  Serial.print(" ");
  Serial.println(distance);
  
  delay(30); //To make servo sweep faster, decrease this value! to Increase, increase the value!




}
