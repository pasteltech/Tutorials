//Code verified 10/11/2020

const int trigPinLeft = 10;
const int echoPinLeft = 11;
const int trigPinRight = 6;
const int echoPinRight = 7;

const int echoTime = 7000; //If the Servo isn't working well this is most likely where the error is.

int durationLeft;
int durationRight;

int distanceLeft;
int distanceRight;


//This sets the samples to average, originally set to 10
int samples = 10;



void setup()
{
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);

  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);

  Serial.begin(115200);

}


//Here we find the distance measurement in centimeters measured by the Ping Sensors
void loop() {

  distanceLeft = (sonicSensor(10, 11));
  delay(50);
  distanceRight = (sonicSensor(6, 7));


  Serial.print(distanceLeft);
  Serial.print(" ");
  Serial.print(distanceRight);
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
