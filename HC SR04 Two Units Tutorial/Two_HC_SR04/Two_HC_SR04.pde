import processing.serial.*;
import java.util.*;
/*
5-17-2017
 Try to create a smooth way to actually draw the rectangle growing, that would probably require saving the current
 state of the rectangle, finding the difference between the current state and the new state and then growing the 
 rectangle from there, that could be done relatively easily. I have to do more tests on how to actually smooth the
 results that the Arduino gives, there is a lot of variation when there is movement. 
 
 */
//stroke(255, 25, 25); stroke(50, 220, 255);
Serial myPort;
static int numberSensors = 2;
int[]values = new int[numberSensors];
Scanner scan;
int scale;
//double scale =((double)height/100);


void setup()
{
  printArray(Serial.list());
  print(scale);
  size(1280, 720);
  surface.setResizable(true);



  String portName = Serial.list()[2];
  myPort = new Serial(this, Serial.list()[2], 9600);

  background(50); //sets the background to a gray color
  delay(50);
}

void draw()
{
  //Sets the scale for the display. 
  scale = (height/100);


  //println("Scale = " + scale);
  // print("Scale" + scale + " hey");
  background(50);
  if (myPort.available()>0)
  {
    
    byte[]inBuffer = new byte[5];
    while (myPort.available() > 0) {
      /*
      println("Available = " + myPort.available());
       int inByte = myPort.read();
       println(inByte);
       */
      inBuffer = myPort.readBytes();
      myPort.readBytes(inBuffer);
      if (inBuffer != null) {
        String myString = new String(inBuffer);
        println(myString);
      }
      
    }
      
      /*
        int start = 0;
       scan = new Scanner(myPort.readString());
       println("Scan = " +scan);
       
       
       
       while (scan.hasNextInt()) {
       values[start] = scan.nextInt();
       println("IN METHOD");
       start = start + 1;
       }
       */

    
      //printArray(values);
      fill(255, 30, 250);
      drawRectangles();
      fill(255);
      drawLine();
      // findDirection();
      //myPort.clear(); //clears the serial port 

      // rect(80,80,80,80);
    }
}
    /*
void findDirection()
     {
     int maxDirection = 0;
     int maxValue = 0;
     for (int i = 0; i < numberSensors; i++)
     {
     if(values[i] > maxValue)
     {
     maxDirection = i;
     maxValue = values[i];
     }
     }
     if(maxDirection == 0)
     text("Left Side is Farther",height/8,width/8);
     if(maxDirection == 1)
     text("Right Side is Farther", height/8,width/8);
     }
     
     */
    void drawRectangles()
    {
      strokeWeight(1);
      fill(50, 220, 255);
      int spacing = (width/(numberSensors+1));
      for (int i = 0; i < numberSensors; i++)
      {
        // print(height/100);

        int dHeight= (int)(values[i]*scale);
        // print(dHeight);
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
      for (int start = 0; start < array.length; start++)
      {
        print(array[start] + " " );
      }
      println();
    }
