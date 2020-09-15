


const int trigPinLeft = 10;
const int echoPinLeft = 11;
const int trigPinRight = 6;
const int echoPinRight = 7;
const int size = 20;
int counter = 0;
int sumRight = 0;
int sumLeft = 0;

const int echoTime = 7000; //If the Servo isn't working well this is most likely where the error is. 

int durationLeft;
int durationRight;

int distanceLeft;
int distanceRight;

void setup() 
{
  pinMode(trigPinLeft,OUTPUT);
  pinMode(echoPinLeft,INPUT);

  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
  
  Serial.begin(9600);

}

void loop() {
     // Serial.println(trigPinLeft);
   // Serial.println(trighPinLeft + " " + echoPrinRight);
  /*

  digitalWrite (trigPinLeft, LOW);
  digitalWrite(trigPinRight,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinLeft, HIGH);
  digitalWrite(trigPinRight,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLeft,LOW);
  digitalWrite(trigPinRight,LOW);
  durationLeft = pulseIn(echoPinLeft,HIGH,7000);
  durationRight = pulseIn(echoPinRight,HIGH,7000);
  Serial.println(durationLeft);
  Serial.println(durationRight);
  distanceLeft = durationLeft*.034/
  Serial.println(distanceLeft);
  distanceRight = durationRight*(.034/2);
  
  Serial.print("Distance Left = ");
  Serial.print(distanceLeft);
  Serial.print("    Distance Right = ");
  Serial.print(distanceRight);
  */
  
  sumRight+=sonicSensor(6,7);
  sumLeft +=sonicSensor(10,11);
  
 
  
  counter = counter +1;
  if(counter == size)
  {
    Serial.print(sumRight/counter);
    Serial.print(" ");
    Serial.println(sumLeft/counter);
    sumRight = 0;
    sumLeft = 0;
    counter = 0;
    
  }
   delay(10);

  


  
  
}
int sonicSensor(int trigPin, int echoPin)
{

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    int duration = pulseIn(echoPin,HIGH,4000);
    //int distance = (duration/2)/29.1;
    if(duration == 0)
        return 100;
    return (duration/2)/29.1;
}


























