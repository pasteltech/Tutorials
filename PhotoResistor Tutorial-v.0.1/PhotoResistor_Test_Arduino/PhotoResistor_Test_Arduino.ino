
int photoPin = 0;
int sum = 0;
int intensity = 0;
const int count = 10;

void setup() {
  pinMode(photoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < count ; i++)
  {
    sum += analogRead(photoPin);
  }
  intensity = (sum/(count*4)); //This number is between 0 and 1024
  //Intensity is from 0 to 255, so we divide 1024/4 to get a fitting number
  int value255 = analogRead(value255);
  value255 = (value255 / 4);
  Serial.println(value255);
  delay(40);
}
