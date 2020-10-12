

void setup()
{

  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel B pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel B pin

}

void loop()
{

  //forward direction motor a
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);
  analogWrite(5, 255);


  // forward direction motor b
  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  analogWrite(6, 255);



}
