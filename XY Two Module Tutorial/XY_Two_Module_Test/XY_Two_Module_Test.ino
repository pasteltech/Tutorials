

//This is for the Right XY ANALOG STICK
const int x_Pin_R = 0; // analog pin connected to X output
const int y_Pin_R = 1; // analog pin connected to Y output
const int button_R = 2;


//This is for the Left XY ANALOG STICK
const int x_Pin_L = 2;
const int y_Pin_L = 3;
const int button_L = 3;


int sum_X_R = 0;
int sum_Y_R = 0;
int average_X_R = 0;
int average_Y_R = 0;

int sum_X_L = 0;
int sum_Y_L = 0;
int average_X_L = 0;
int average_Y_L = 0;



const int count = 10; //We average this amount of values, and print that in the Serial Monitor
/*
    Make sure the serial monitor baud rate is the same, in Arduino and in Processing


*/



void setup() {
  pinMode(button_R, INPUT);
  pinMode(button_L, INPUT);

  digitalWrite(button_R, HIGH);
  digitalWrite(button_L, HIGH);

  Serial.begin(9600); // Make sure the baud rate is the same in processing, common mistake
  delay(100); //delays 100ms
}

void loop() {

  /*This loop takes the average of count number of elements
     The sensor is a little noisy, so taking the average helps prevents some jittering
  */
  for (int i = 0; i < count; i ++)
  {
    sum_X_R += analogRead(x_Pin_R);
    sum_Y_R += analogRead(y_Pin_R);

    sum_X_L += analogRead(x_Pin_L);
    sum_Y_L += analogRead(y_Pin_L);
    delayMicroseconds(100); //maximum reading rate for analog input is 100 microseconds, don't decrease
  }
  average_X_R = sum_X_R / count;
  average_Y_R = sum_Y_R / count;

  average_X_L = sum_X_L / count;
  average_Y_L = sum_X_L / count;
  

  Serial.print(digitalRead(button_R));
  Serial.print(" ");
  Serial.print(average_X_R);
  Serial.print(" ");
  Serial.print(average_Y_R);
  Serial.print(" ");
  Serial.print(digitalRead(button_L));
  Serial.print(" ");
  Serial.print(average_X_L);
  Serial.print(" ");
  Serial.print(average_Y_L);
  Serial.print("\n");
  sum_X_R = 0;
  sum_Y_R = 0;

  sum_X_L = 0;
  sum_Y_L = 0;
  //delay(30);
}


