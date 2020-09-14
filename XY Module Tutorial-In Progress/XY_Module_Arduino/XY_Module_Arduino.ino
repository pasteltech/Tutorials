const int xPin = 0; // analog pin connected to X output, yellow
const int yPin = 1; // analog pin connected to Y output, blue
const int pressed = 2; //This is a digital pin, not analog, white

int sumX = 0;
int sumY = 0;
int averageX = 0;
int averageY = 0;
int x = 0;
int y = 0;
int baseX;
int baseY;
int magnitude;
int xSquare = 0;
int ySquare = 0;
int maxDisplacement = 0;

const int count = 10; // We use this number to get an average of 10 values
/*
   Here we initialize the following:
   1.   Set up a digital pin to read if the stick is pressed.

   2.   We then read the analog pins of the xPin and yPin.
        We do this because we need the base or default
        starting x and y positions of the joystick.
        We then use these numbers and see how to they
        change in order calculate x,y movement.

*/
void setup() {

  pinMode(pressed, INPUT);
  digitalWrite(pressed, HIGH);


  baseX = analogRead(xPin);
  baseY = analogRead(yPin);

  Serial.begin(9600);
}
/*In the following looping method



        The Data is outputted in the following format
*/
void loop() {





  for (int start = 0; start < count; start++)
  {
    sumX += analogRead(xPin);
    sumY += analogRead(yPin);
    delayMicroseconds(100);// Maxium reading rate for analog input is 100 microseconds, so only increase from here
  }
  averageX = sumX / count;
  averageY = sumY / count;
  if (averageY > 600)
  {
    Serial.print("1"); // means right Direction
  } else if (averageY < 400)
  {
    Serial.print("2");//means left Direction
  } else if (averageX > 600)
  {
    Serial.print("3");//up Direction
  } else if (averageX < 400)
  {
    Serial.print("4");//down Direction
  } else
  {
    Serial.print("0");
  }

  Serial.print(" ");
  Serial.print(digitalRead(pressed));
  Serial.print(" ");
  Serial.print(averageX);
  Serial.print(" ");
  Serial.print(averageY);


  Serial.print("\n");
  sumX = 0;
  sumY = 0;
  delay(100);



}
