
import processing.serial.*;
import java.util.*;

Serial myPort;
static int numberSensors = 2;
int[]values = {};
Scanner scan;
int scale;
String val;
int count = 0;
//double scale =((double)height/100);


void setup()
{

  print(scale);
  size(1280, 720);
  surface.setResizable(true);



  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 115200);

  background(50); //sets the background to a gray color
  delay(150);
}

void draw()
{
  scale = (height/100);
  //print(scale);
  background(50);
  if (myPort.available()>0)
  {

    val = myPort.readStringUntil('\n');
    if (val!=null)
    {
      values = int(split(val, ' '));
      print((count++) + " ");
      printArray(values);
    }
  }
 
  drawRectangles();
  fill(255);
  drawLine();
  //findDirection();

  myPort.clear(); //clears the serial port
}
void findDirection()
{
  int maxDirection = 0;
  int maxValue = 0;
  for (int i = 0; i < numberSensors; i++)
  {
    if (values[i] > maxValue)
    {
      maxDirection = i;
      maxValue = values[i];
    }
  }
  if (maxDirection == 0)
    text("Left Side is Farther", height/8, width/8);
  if (maxDirection == 1)
    text("Right Side is Farther", height/8, width/8);
}
void drawRectangles()
{

  strokeWeight(5);
  fill(50, 220, 255);
  int spacing = (width/(numberSensors+1));
  for (int i = 0; i < numberSensors; i++)
  {
    // print(height/100);
    int dHeight= (int)(values[i]*scale);
    rect(spacing, height, 50, -dHeight);
    textSize(32);
    text(values[i], spacing-(50), height);
    // println( "Spacing = " +values[i] + " " + scale);

    spacing = spacing + spacing;
  }

  //println();
}
void drawLine()
{
  stroke(255, 25, 25);
  strokeWeight(3);
  int spacing = (width/(numberSensors+1));
  int leftHeight= (int)(values[0]*scale);
  int rightHeight = (int)(values[1]*scale);
  line(spacing, height-leftHeight, spacing*2, height-rightHeight);
  stroke(255);
}
void printArray(int [] array)
{
  for (int start = 0; start < array.length-1; start++)
  {
    print(array[start] + " " );
  }

  println();
}
