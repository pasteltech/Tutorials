
import processing.serial.*;
import java.util.*;


Serial myPort; 
Scanner scan;
float temp;
int limit = 20;
final int lowerLimit = -40; //Both of these are in Celsius
final int upperLimit = 215; //In Celsius
final int maxColor = 255; //IN RGB 255,255,255 IS THE MAX
int diameter = 100;
int add = 1;
int startX = 0;
int startY = 0;
float[]tList = new float[5];







void setup()
{
  



    size(1280, 720);
   

    surface.setResizable(true);
    delay(100);
    String portName = Serial.list()[1];
    myPort = new Serial(this, portName, 9600);
}

void draw()
{

    background(122);
    
    if (myPort.available()>0)
    {
        int start = 0;
        scan = new Scanner(myPort.readString());
        while (scan.hasNextFloat())
        {
            //temp = scan.nextFloat();
            tList[start] = scan.nextFloat();
            start++;
        }
        System.out.println("Temperature = " + temp);
    }

    //drawThermometer(800, 80, width/4, height/2, temp);
    for(int i = 0; i < tList.length;i++)
    {
        println(tList[i]);
        if(tList[i] != 0)
        {
            drawThermometer(800,80,width/4,100+200*(i),tList[i]);
        }
    }

    myPort.clear();
}

void drawThermometer(int w, int h, int x, int y, float temp)
{
    int blue = 255;
    int red = 0;
    int startX = x;
    int unit = w/255; //since there are 255 colors
    for (int i = 0; i < 255; i++)
    {

        fill(red, 0, blue);
        noStroke();

        // fill(125);
        rect(x+=unit, y, unit, h);
        //this draws out the temperature marks
        if (i%25 == 0)
        {
            int tempLine = lowerLimit+i;
            fill(255);
            rect(unit+x, y+h, 1, 5);
            text(tempLine + "°", unit+x, y+(h*1.3));
        }
        //This draws out the current temperature line
        if (i == (int)temp+40)
        {
            fill(red, 0, blue);
            rect((i*unit)+startX, y-h, 3, h);
            textSize(15);
            text(temp, (i*unit)+startX, y-h);
           
        }
        blue--;
        red++;
    }
}