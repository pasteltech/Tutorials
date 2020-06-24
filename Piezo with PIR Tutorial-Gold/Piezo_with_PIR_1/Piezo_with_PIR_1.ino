/* Arduino tutorial - Buzzer / Piezo Speaker
   More info and circuit: http://www.ardumotive.com/how-to-use-a-buzzer-en.html
   Dev: Michalis Vasilakis // Date: 9/6/2015 // www.ardumotive.com */
   //Use a 2N2222 Transistor


const int buzzer = 9; //buzzer to arduino pin 9


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(8,INPUT);
  Serial.begin(9600); //9600 Baud Rate

}

void loop(){
  boolean isOn = digitalRead(8);
  
  //Serial.println(isOn);
  if(isOn == true)
  {
    Serial.println("Motion Detected");
    tone(buzzer,3000);
  }
  else
  {
    noTone(buzzer);
    Serial.println("---------------");
  }
  delay(200);
  /*
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
  */
}
