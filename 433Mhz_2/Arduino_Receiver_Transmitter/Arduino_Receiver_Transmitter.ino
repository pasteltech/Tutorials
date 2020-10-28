// Maurice Ribble 
// 8-30-2009
// http://www.glacialwanderer.com/hobbyrobotics
// Used Arduino 0017
// This is a simple test app for some cheap RF transmitter and receiver hardware.
// RF Transmitter: http://www.sparkfun.com/commerce/product_info.php?products_id=8945
// RF Receiver: http://www.sparkfun.com/commerce/product_info.php?products_id=8948

// This says whether you are building the transmistor or reciever.
// Only one of these should be defined.
#define TRANSMITTER
//#define RECEIVER

// Arduino digital pins
#define BUTTON_PIN  2
#define LED_PIN     13

// Button hardware is setup so the button goes LOW when pressed
#define BUTTON_PRESSED LOW
#define BUTTON_NOT_PRESSED HIGH

void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(1200);  // Hardware supports up to 2400, but 1200 gives longer range
}

#ifdef TRANSMITTER
void loop()
{
  static int prev_button = BUTTON_NOT_PRESSED;  // Previous button press value
  int        cur_button;                        // Current button press value

  cur_button = digitalRead(BUTTON_PIN);

  if ((prev_button == BUTTON_NOT_PRESSED) && (cur_button == BUTTON_PRESSED))
  {
    writeUInt(3); // Put any number you want to send here (71 is just a test)
  }
  writeUInt(256);
 
  delay(1000); // Debounce button
  prev_button = cur_button;
}
#endif //TRANSMITTER

#ifdef RECEIVER
void loop()
{
  boolean light_led = false;

  if (readUInt(true) == 271) // Check to see if we got the 271 test number
  {
    //int l = readUInt(val);
    light_led = true;
   Serial.println((int)readUInt(true));
   
  }
  Serial.println((int)readUInt(true));
  
  if (light_led)
  {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
  }
}
#endif //RECEIVER


