


const int trigPinLeft = 10;
const int echoPinLeft = 11;
const int trigPinRight = 6;
const int echoPinRight = 7;

const int echoTime = 7000; //If the Servo isn't working well this is most likely where the error is.

int durationLeft;
int durationRight;

int distanceLeft;
int distanceRight;

void setup()
{
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);

  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);

  Serial.begin(9600);

}

void loop() {

  Serial.print(sonicSensor(10, 11));
  Serial.print(" ");
  Serial.println(sonicSensor(6, 7));
  delay(10);
  
  delay(500);
}
int sonicSensor(int trigPin, int echoPin)
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH, 7000);
  //int distance = (duration/2)/29.1;
  return (duration / 2) / 29.1;
}


























