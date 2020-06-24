/*
   Arduino Tutorial- Piezo Happy Birthday Tutorial
   More Information: http://www.pasteltech.com
   Developer: Jose Lopez

*/

const int buzzer = 9; //buzzer to arduino pin 9
const int wait = 400;
int hertz;
/*
   196-G3
   220-A3
   261-C4
   246-B3
   294-D4
   370-F#
   329-E
   349-F
*/
//Happy Birthday song, released to the public domain on June 28, 2016.
int a[26] = {196, 196, 220, 196, 261, 246, 196, 196, 220, 196, 294, 261, 196, 196, 370, 329, 261,
             246, 220, 349, 349, 329, 261, 294, 261
            };

const int songlength = 26;
void setup() {

  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  Serial.begin(9600);

}

void loop() {

  for (int count = 0; count < songlength; count++)
  {
    hertz = a[count];
    noTone(buzzer);
    delay(50);
    tone(buzzer, hertz);
    delay(wait);
  }
  noTone(buzzer);
  delay(600);

}
