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
        line(distancePixels*cos(radians(angle)),-distancePixels*sin(radians(angle)),950*cos(radians(angle)),-950*sin(radians(angle)));
    }
    popMatrix();
    
}
    
void drawLine()
{
    
    pushMatrix();
    strokeWeight(9);
    stroke(50,220,255);
    translate(width/2,height);
    line(0,0,height*.95*cos(radians(angle)),-height*.95*sin(radians(angle)));
    smooth();
    popMatrix();
    
    
    
    
    
}
void drawPolarGrid()
{
        int diameter = width;
        //int diameter = width-(width/20);
        
    for(int i = 0; i < 10; i ++)
    {   stroke(50,150,255);
        strokeWeight(3);
        noFill();
        arc((width/2),height,diameter,diameter,PI,PI+PI);
        diameter= diameter-(width/10);
        stroke(0);
        smooth();
    }
}

void drawData()
{
   
   // rect(0,0,width,height/30);
   //stroke(50,150,255);
    fill(30);
    rect(0,height-(height/19),width,height/20);
    
    //Text Display the Data on Distance and Angle
    fill(50,150,255);
    text("Distance: " + distance, width-(width/2),height-(height/100));
    text("Angle: " + angle, width-(width/5), height-(height/100));
    
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
       
        
        //String[] valuesSplit = split(values,'.');
        // (Angle Distance) Separated by a space ex: 180 50
           /*Code to parse the string and store the values into angle and distance*/
           int index1 = values.indexOf(" ");
           String angleString = values.substring(0,index1);
           String distanceString = values.substring(angleString.length()+1, values.length());
           
           //storng values into angle and distance
           angle = int(angleString);
           distance = int(distanceString.trim());
          
         
           pushMatrix();
           //translate(0,-40);
           translate(0,-height/20);
           textSize(40);
           drawLine();
           drawObject();
           drawPolarGrid();
           popMatrix();
           drawData();
           
           smooth();
           // distance = int(valuesSplit[1]);
        
       myPort.clear();//clears the serial port list of inputted distances
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
 