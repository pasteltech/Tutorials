//Created by Jose for PastelTech
import processing.serial.*;
import java.util.*;

Serial myPort; // Create object from the serial class
String values; // store the data received from the serial port
int distance = 0;
int angle = 0;
PImage img;
void setup()
{
  frameRate(60);
  size(1280, 720);
  //surface.setResizable(true);

  String portName = Serial.list()[5];
  myPort = new Serial(this, portName, 9600); 

  background(0);
  smooth(4);
  delay(50);
  
  
}

void draw()
{
  
  //The following code reads the serial port data from the Arduino and puts it to use in the processing sketch
  if (myPort.available()>0)
  {
    values = myPort.readString();//reads the inputted string until the new line character

    /*Code to parse the string and store the values into angle and distance*/
    int index1 = values.indexOf(" ");
    String angleString = values.substring(0, index1);
    String distanceString = values.substring(angleString.length()+1, values.length());

    //stores values into angle and distance
    angle = int(angleString);
    
    distance = int(distanceString.trim());
  
    if(angle == 179)
    {
      
      fill(0);
      rect(0,0,width/5,height/5);
      saveFrame("screenshot.tif");
      img = loadImage("screenshot.tif");
      
      
      image(img,0,0,width/6,height/6);
     
      
    }
    
    pushMatrix();
    translate(0, -height/20);
    textSize(40);
    drawLine();
    drawObject();
    drawPolarGrid();
    popMatrix();
    drawData();
    
    


    myPort.clear();//clears the serial port list of inputted distances
  }else{
    delay(30);
  }
  
} 
void drawObject()
{
  
  pushMatrix();
  translate(width/2, height);
  strokeWeight(9);
  stroke(255, 25, 25);
  int distancePixels = (width/200)*distance;

  if (distance<100)
  {
    line(distancePixels*cos(radians(angle)), -distancePixels*sin(radians(angle)), (width/2)*cos(radians(angle)), (-width/2)*sin(radians(angle)));
  }
  popMatrix();
}

void drawLine()
{
  pushMatrix();

  strokeWeight(9);
  stroke(50, 220, 255);
  translate(width/2, height);
  line(0, 0, (width/2)*cos(radians(angle)), (-width/2)*sin(radians(angle)));

  popMatrix();
}
/*
This method draws a polar grid, basically a series of concentric circles that are separated by the same distance
 */
void drawPolarGrid()
{
  //Instead of setting the sizes of these int to fixed numbers, we the width of the screen, which can change and adjust
  int diameter = width;

  for (int i = 0; i < 10; i ++)
  {   
    stroke(50, 150, 255);
    strokeWeight(3);
    noFill();

    arc((width/2), height, diameter, diameter, PI, PI+PI); //creating the circles
    textSize(20);
    stroke(0);
    fill(255);
    int cm = 100-(i*10);
    text("  "+ cm, (width/2)+diameter/2, height-(height/40));
    text("  "+ cm, (width/2)-diameter/2, height-(height/40));
    text(""+ cm, (width/2), height-(diameter/2));
    diameter= diameter-(width/10);
    
    stroke(0);
  }
  textSize(40);
}
/*
    Here we draw the distance and the angle measurements
 */
void drawData()
{
  fill(30);
  rect(0, height-(height/19), width, height/20);

  //Text Display the Data on Distance and Angle
  fill(255);
  text("Distance: " + distance + "cm", width-(width/2), height-(height/100));
  text("Angle: " + angle + "°" , width-(width/5), height-(height/100));
  
}