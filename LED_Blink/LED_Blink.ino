int pin = 8; //so we can change the pin easily if we want
void setup()
{
  //initialize in here
  pinMode(pin,OUTPUT);
}
void loop()
{
  //this loops continously
  digitalWrite(pin,HIGH);
}

