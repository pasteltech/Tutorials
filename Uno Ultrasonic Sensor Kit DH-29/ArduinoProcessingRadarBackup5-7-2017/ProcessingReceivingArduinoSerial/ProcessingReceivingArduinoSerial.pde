import controlP5.*;
import processing.serial.*;
import java.util.*;
List<Line> drawable = new ArrayList<Line>();
Serial myPort; // Create object from the serial class
String values; // store the data received from the serial port
int largestValue = 0;
int distance = 0;
int angle = 0;
int baseUnit = 800/100; // We want a scale factor so 8 vertical pixels equal 1cm in distance
int yPos = height;
int distanceFromCenter;
int dy = 20;
boolean isHitting = false;
/*Is there a way to skip a method for a certain amount of time?*/
void setup()
{
    size(1600,800);
    surface.setResizable(true);
    String portName = Serial.list()[1];
    background(0);
    myPort = new Serial(this,portName,9600); 
   // noLoop();
}
void drawObject()
{
    pushMatrix();
    translate(width/2,height);
    strokeWeight(9);
    stroke(255,25,25);
    int distancePixels = distance*baseUnit;
    if(distance<100)
    {
       // line(distancePixels*cos(radians(angle)),-distancePixels*sin(radians(angle)),950*cos(radians(angle)),-950*sin(radians(angle)));
       line(distancePixels*.8*cos(radians(angle)),-distancePixels*.8*sin(radians(angle)),distancePixels*.8*cos(radians(angle)),-distancePixels*.8*sin(radians(angle)));
    }
    popMatrix();
    
}
    
void drawLine()
{
    
    pushMatrix();
    strokeWeight(9);
    stroke(30,250,60);
    translate(width/2,height);
    line(0,0,height*.95*cos(radians(angle)),-height*.95*sin(radians(angle)));
    popMatrix();
    
    
    
    
    
}

void drawData()
{
    pushMatrix();
    translate(0,height);
}
void draw()
{
   //background(60);
  //  println(myPort.size());
    if(myPort.available()>0)
    {
        // if the data is available
        //values.trim()
        values = myPort.readString();//reads the inputted string until the new line character
        text(values,50,50);
        
        //String[] valuesSplit = split(values,'.');
        // (Angle Distance) Separated by a space ex: 180 50
     
           int index1 = values.indexOf(" ");
           String angleString = values.substring(0,index1);
           String distanceString = values.substring(angleString.length()+1, values.length());
           text(distanceString, 50,140);
           angle = int(angleString);
           distance = int(distanceString.trim());
           text(angle,50,80);
           text(distance,50,300);
           drawLine();
           drawObject();
            
           // distance = int(valuesSplit[1]);
        
       myPort.clear();//clears the serial port list of inputted distances
    }

int diameter = width;
for(int i = 0; i < 10; i ++)
{    stroke(100,50,250);
    strokeWeight(3);
    noFill();
     arc((width/2),height,diameter,diameter,PI,PI+PI);
     diameter= diameter-(width/10);
    stroke(0);
}

 if(values!=null && distance < 100) // We are trying to check if the serial monitor read something and that converted string to int is < 100cm
 {
  
     textSize(40);
     fill(255);
     //int distance = int(val.trim()); // Now we have the distance of the sensor, in this case we needed to trim the null terminating character I think! 
     println(distance);
     if(distance>largestValue)//Trying to find the largest miscellaneous value 
      {
          largestValue = distance;
          
      }
      text ("Largest Distance in cm: "+ largestValue, width/10, height-(height/10));
     
    
     if(distance <100) //We want to take away values that are too high, and likely wrong
     {
         distanceFromCenter = height-distance;
         text("Distance in cm: " + distance,width/10,height-(height/30)); //text(Text outputted, x, y,);
         //println(val);
         // We will draw a ruler that attempts to show how far something is
         int store = distanceFromCenter;
         
     }
     fill(30,255,30);
     
     if(yPos<0)
     {
         yPos = height;
     }
     
     
    
     
    //delay(50);
     //delay(40); // Stable time delay
    // delay(20);
 }
     
} 
void mousePressed()
{
    redraw();
}
public class Line
{
    public int x1,x2=0;
    public int y1,y2=0;
    //constructor
    public Line(int a1, int a2, int b1, int b2)
    {
        
        x1=a1;
        x2=a2;
        y1=b1;
        y2=b2;
        
    }
    public Line(int a1, int b1)
    {
        x1=a1;
        y1=b1;
    }
    public int getX()
    {
        return x1;
    }
    public int getY()
    {
        return y1;
    }
    
} 
 