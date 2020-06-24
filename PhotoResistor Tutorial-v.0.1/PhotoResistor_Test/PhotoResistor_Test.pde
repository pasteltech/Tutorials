import processing.serial.*;
import java.util.*;


Serial myPort;
Scanner scan;
int[]values = new int[2];
int intensity = 1;
boolean loop = true;
boolean startDelay = true;




int Y_AXIS = 1;
int X_AXIS = 2;
color b1, b2, c1, c2;



int count = 0;
int maxTries = 3;
void setup()
{
    size(1280, 720, P3D);
    surface.setResizable(true);
    
    String portName = Serial.list()[1];
    myPort = new Serial(this, portName, 9600);

    background(50); //sets the background to a gray color
    delay(50);

    // Define colors
    b1 = color(255);
    b2 = color(0);
    c1 = color(0);
    c2 = color(255);
}

void draw()
{
    if (startDelay) { 
        delay(100); 
        startDelay = false;
        // other arduino initialization stuff
    }
    background(0);
    if (myPort.available()>0)
    {

        scan = new Scanner(myPort.readString());

        while (scan.hasNextInt()) {
            intensity = scan.nextInt();

            // printArray(values);
        }
    }
    fill(255);
    textSize(30);
    text("Light Intensity from 0-255:\n" + "Current Intensity = " + intensity, width/8, height/8);
    
    fill(intensity);

    //This is where we draw the sphere
    pushMatrix();
    noStroke();
    rotateX(radians(.002));
    translate(width/2, height/2, 0);
    lights();
    //sphereDetail(30);
    sphere(height/4);
    popMatrix();
    
   
    myPort.clear(); //clears the serial port 
    delay(5);
    
    setGradient(width/4, (height/2)+(height/3), width/3, height/8, c2, c1, X_AXIS);
}

void setGradient(int x, int y, float w, float h, color c1, color c2, int axis ) {

    noFill();

    if (axis == Y_AXIS) {  // Top to bottom gradient
        for (int i = y; i <= y+h; i++) {
            float inter = map(i, y, y+h, 0, 1);
            color c = lerpColor(c1, c2, inter);
            stroke(c);
            line(x, i, x+w, i);
        }
    } else if (axis == X_AXIS) {  // Left to right gradient
        float spacing =  w/255; //We divide the width into 255 pieces
        fill(intensity);
        rect(x+w-(intensity*spacing),y-h/2,1,50);
        noFill();
        for (int i = x; i <= x+w; i++) {
            float inter = map(i, x, x+w, 0, 1);
            color c = lerpColor(c1, c2, inter);
            stroke(c);
            line(i, y, i, y+h);
        }
    }
}