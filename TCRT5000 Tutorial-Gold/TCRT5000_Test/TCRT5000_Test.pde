
import processing.serial.*;
import java.util.*;


Serial myPort; 
Scanner scan;
int analogValue = 0; //the Value that is read from the analog sensor 0 -1024



void setup()
{
  
  //This sets the screen to be a 600 by 400 screen
  
  size(600, 400, P3D);
  surface.setResizable(true);
  delay(100);
  
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
}

void draw()
{

  background(122);//here we set the background color to a nice grey
  lights();
  pushMatrix();
  translate(width/2, height/2);
  
  //The following chunk of code reads the serial output of the Arduino Sketch into processing
  if (myPort.available()>0)
  {
    scan = new Scanner(myPort.readString());
    while (scan.hasNextInt())
    {
      analogValue = scan.nextInt();
      analogValue = (analogValue/4); //Changes the value from 0-1024 to roughly 0-255
      
    }
    
  }
 
  println(analogValue);
  fill(analogValue); //this sets the fill value to change
  noStroke();
  sphere(height/6);
 
  fill(255);
  if (analogValue<=8)
  {
    text("Finger is touching the Sensor.", width/5, 0);
  }

  text("Current Value: " + analogValue, width/5, 50);

  popMatrix();

  myPort.clear();
}