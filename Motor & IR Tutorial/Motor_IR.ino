/*
 * Sketch modified by Enjoying Electronics: http://www.instructables.com/member/Enjoying+Electronics/
 Code based off of: 
 * IRremote
 * Version 0.1 July, 2009 
 * Copyright 2009 Ken Shirriff
 * For details, see http://arcfn.com/2009/08/multi-protocol-infrared-remote-library.html
 
 * Special thanks to dablondeemu http://www.instructables.com/member/dablondeemu/
 * and his instructable listed below, IR Remote Controlled Color Changing Cloud (Arduino) 
 * http://www.instructables.com/id/IR-Remote-Controlled-Color-Changing-Cloud-Arduino/  
 
 
 * Lets get started:
 
 The IR sensor's pins are attached to Arduino as so:
 Pin 1 to Vout (pin 11 on Arduino)
 Pin 2 to GND
 Pin 3 to Vcc (+5v from Arduino)

*/

/*******************CODE BEGINS HERE********************/
//gnd vcc vout
#include <IRremote.h>

int IRpin = 4;
int led = 7;
int led2 = 2;
//int ledState = LOW;             // ledState used to set the LED
//long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 175;    
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

IRrecv irrecv(IRpin);
//IRrecv irrecv2(IRpin2);

decode_results results;
//decode_results results2;

void setup()
{
 // pinMode(led,OUTPUT);
  Serial.begin(9600);
  //irrecv2.enableIRIn();
  irrecv.enableIRIn(); // Start the receiver
    //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
  pinMode(7,OUTPUT);
  pinMode(2,OUTPUT); 

}

void loop() 
{
  int alpha;
  unsigned long currentMillis = millis();
   int first = 0;
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
    {
      ledState = HIGH; 
       digitalWrite(7,HIGH);
    digitalWrite(2,LOW);
    }
    else
    {
      ledState = LOW;
      digitalWrite(7,LOW);
      digitalWrite(2,HIGH);
  
    }

    // set the LED with the ledState of the variable:
    
    //digitalWrite(7,ledState);
   // digitalWrite(2,ledState);
    
  }
    
  alpha = 0;
  int alpha2;
  alpha2 = 0;

  
  if (irrecv.decode(&results)) 
    {  
     
      alpha = (results.value);
     
       
    if(alpha!= 4294967295)
    {
      /*
      digitalWrite(12,HIGH);
      digitalWrite(9,LOW);
      analogWrite(3,255);
      */
      
      Serial.println(alpha);
      if(alpha == 3825|| alpha == 9945 || alpha == -22951||  alpha == 144||
      alpha == 2192||alpha == 1785|| alpha == -12751|| alpha == 11985 || alpha ==28305 ||alpha == -20911||alpha == -4591||alpha == 4335 || alpha == -24481 || alpha == 16575)
      {
        
          
          int slow = 200;
          int fast = 255;
          
            if(alpha == 1785|| alpha == -12751)
            {
      
             
             //forward direction motor a
            digitalWrite(13,HIGH);
            digitalWrite(8,LOW);
            analogWrite(5,130);
            
            
            // forward direction motor b
            digitalWrite(12,LOW);
            digitalWrite(9,LOW);
           // digitalWrite(12,LOW);
            analogWrite(6,130);
            
            }
                  if(alpha == 3825)
            {
             
             
             //forward direction motor a
            digitalWrite(13,HIGH);
            digitalWrite(8,LOW);
            analogWrite(5,180);
            
            
            // forward direction motor b
            digitalWrite(12,LOW);
            digitalWrite(9,LOW);
           // digitalWrite(12,LOW);
            analogWrite(6,180);
            
            }
                  if(alpha == 9945)
            {
         
             
             //forward direction motor a
            digitalWrite(13,HIGH);
            digitalWrite(8,LOW);
            analogWrite(5,255);
            
            
            // forward direction motor b
            digitalWrite(12,LOW);
            digitalWrite(9,LOW);
           // digitalWrite(12,LOW);
            analogWrite(6,255);
            
            }
            
            if(alpha == 4335)
             {
                  //forward direction motor a
            digitalWrite(13,HIGH);
            digitalWrite(8,LOW);
            analogWrite(5,75);
            
            
            // forward direction motor b
            digitalWrite(12,LOW);
            digitalWrite(9,LOW);
           // digitalWrite(12,LOW);
            analogWrite(6,75);
            
               
             }
            
            if(alpha == 656||alpha == -4591|| alpha == 144)
            {
             digitalWrite(8, HIGH);  //Engage the Brake for Channel A
             digitalWrite(9, HIGH);  //Engage the Brake for Channel B
             
              
            }
           
            if(alpha == 28305)
            {
                //forward direction motor a
                digitalWrite(13,HIGH);
                digitalWrite(8,LOW);
                analogWrite(5,70);
                
                
                // forward direction motor b
                digitalWrite(12,LOW);
                digitalWrite(9,LOW);
                // digitalWrite(12,LOW);
                analogWrite(6,175);
            }
            
            if(alpha == -20911)
            {
               //forward direction motor a
                digitalWrite(13,HIGH);
                digitalWrite(8,LOW);
                analogWrite(5,175);
                
                
                // forward direction motor b
                digitalWrite(12,LOW);
                digitalWrite(9,LOW);
                // digitalWrite(12,LOW);
                analogWrite(6,70);
            }
             if(alpha == 1275)
             {
                          //forward direction motor a
                    digitalWrite(13,LOW);
                    digitalWrite(8,LOW);
                    analogWrite(5,255);
                    
                    
                    // forward direction motor b
                    digitalWrite(12,HIGH);
                    digitalWrite(9,LOW);
                   // digitalWrite(12,LOW);
                    analogWrite(6,255);
               
             }   
            if(alpha == 11985)
             {
                          //forward direction motor a
                    digitalWrite(13,LOW);
                    digitalWrite(8,LOW);
                    analogWrite(5,140);
                    
                    
                    // forward direction motor b
                    digitalWrite(12,HIGH);
                    digitalWrite(9,LOW);
                   // digitalWrite(12,LOW);
                    analogWrite(6,140);
               
             }       
      
      }  
    }
    //delay(200);
    if(alpha == -31111)
     {
        digitalWrite(8, HIGH);  //Engage the Brake for Channel A
        digitalWrite(9, HIGH);  //Engage the Brake for Channel B
     }
    
       
      irrecv.resume();   // Receive the next value
     // near = false;
  
    }
 
  
}
