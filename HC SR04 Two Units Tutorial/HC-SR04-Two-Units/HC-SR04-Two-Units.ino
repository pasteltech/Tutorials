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


//This sets the samples to average
int samples;



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
  delay(33);
  distanceRight = (sonicSensor(6, 7));


  Serial.print(distanceLeft);
  Serial.print(" ");
  Serial.print(distanceRight);
  Serial.println(" ");

  delay(200);

}
int sonicSensor(int trigPin, int echoPin)
{
  int duration;
  
  int samples = 1;
  for (int i = 0; i < samples; i++)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    pinMode(echoPin, INPUT);
    duration+= pulseIn(echoPin, HIGH, 10000);
  }



  return (duration / (2*samples) / 29.1);
}
