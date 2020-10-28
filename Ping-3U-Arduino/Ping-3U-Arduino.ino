/*
 * Code for Arduino Processing 3U-Ping Sensor
 */

//Each set of echo and trig pins corresponds to an HC-SR04 Sensor
const int echoPin1 = 13;
const int trigPin1 = 12;
const int echoPin2 = 11;
const int trigPin2 = 10;
const int echoPin3 = 9;
const int trigPin3 = 8;



//The amount of time the system waits for an echo response
const int echoTime = 7000; 

//Used to store the measurements from each sensor
int distance1=0;
int distance2=0;
int distance3=0;


//This sets the samples to average, originally set to 20
const int samples = 40;


void setup()
{
  

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  //Begins serial monitor at a Baud rate of 115200
  Serial.begin(115200);

}


//Here we find the distance measurement in centimeters measured by the Ping Sensors
void loop() {
  //Each of the following calls the sonicSensor function
  distance1 = (sonicSensor(trigPin1, echoPin1));
  distance2 = (sonicSensor(trigPin2, echoPin2));
  distance3 = (sonicSensor(trigPin3, echoPin3));

  //Prints each distance to the serial monitor
  Serial.print(distance1);
  Serial.print(" ");
  Serial.print(distance2);
  Serial.print(" ");
  Serial.print(distance3);
  Serial.println(" ");


  //Change this delay to limit printing
  delay(200);

}

//The following function returns the average of #samples
int sonicSensor(int trigPin, int echoPin)
{
  int distSum;
  long duration;
  int dAverage = 0;
  int distance;

  //This loops a sample number of times
  for (int i = 0; i < samples; i++)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration= pulseIn(echoPin, HIGH, echoTime);
    distance = (duration/2)/29.1;
    distSum+= distance;

  }

  dAverage = distSum/samples;


  return dAverage;
}
