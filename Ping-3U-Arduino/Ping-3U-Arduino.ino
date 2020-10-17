//Code verified 10/11/2020

const int trigPin1 = 6;
const int echoPin1 = 7;
const int trigPin3 = 10;
const int echoPin3 = 11;


const int echoTime = 7000; //If the Servo isn't working well this is most likely where the error is.

int distance1;
int distance3;


//This sets the samples to average, originally set to 20
int samples = 20;



void setup()
{
  

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  //pinMode(trigPin2,OUTPUT);
  //pinMode(echoPin2,INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  Serial.begin(115200);

}


//Here we find the distance measurement in centimeters measured by the Ping Sensors
void loop() {
  distance1 = (sonicSensor(trigPin1, echoPin1));
  delay(33);
  //distance2 = (sonicSensor(trigPin2, echoPin2));
  //delay(33);
  distance3 = (sonicSensor(trigPin3, echoPin3));
  


  Serial.print(distance1);
  Serial.print(" ");
  
  //Serial.print(distance2);
  //Serial.println(" ");
  
  Serial.print(distance3);
  Serial.println(" ");
  
  delay(200);

}
int sonicSensor(int trigPin, int echoPin)
{
  int distSum;
  int duration;
  int dAverage = 0;
  int distance;
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
    delay(2);

  }

  dAverage = distSum/samples;


  return dAverage;
}
