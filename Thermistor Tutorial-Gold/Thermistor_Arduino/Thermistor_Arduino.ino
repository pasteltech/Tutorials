// the value of the 'other' resistor
#define RINITIAL 10000

// What pin to connect the sensor to
#define THERMISTORPIN A0
#define COUNT 10
#define BVALUE 3950;

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  float reading;
  float thermistor;
  float stein;
  float readingSum;

  reading = analogRead(THERMISTORPIN);

  //Serial.print("Analog reading ");
  //Serial.println(reading);
  for (int start = 0; start < COUNT; start++)
  {
    readingSum += analogRead(THERMISTORPIN);
  }
  readingSum /= COUNT;
  // Serial.print("Reading Average = ");
  // Serial.println(readingSum);
  // convert the value to resistance
  reading = readingSum;
  reading = (1023 / reading)  - 1;     // (1023/ADC - 1)
  thermistor = RINITIAL / reading; // 10K / (1023/ADC - 1)
  stein = thermistor / RINITIAL;
  stein = log(stein);
  stein /= BVALUE;
  stein += 1.0 / (298.15);
  stein = 1.0 / stein;
  stein -= 273.15;

  Serial.println(stein);
  

  // Serial.print("Reading Average = ");
  //Serial.print(readingSum);
  readingSum = 0;
  Serial.println();


  delay(1000);
}
