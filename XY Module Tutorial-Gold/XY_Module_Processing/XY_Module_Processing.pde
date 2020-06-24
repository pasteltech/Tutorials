import processing.serial.*;
import java.util.*;

Serial myPort; 
Scanner scan;
int xPos = width/2;
int yPos = height/2;
int direction;
int previousDirection;
int addFactor = 1;

int count = 0;

/*
*The following method setups the default screen size, sets the values of 
 xPos and yPos, along with creating a Serial Monitor in processing, remember to
 close the COM Monitor in Arduino if it is open. 
 *
 */
void setup()
{
  size(1280, 720, P3D);
  xPos = width/2;
  yPos = height/2;

  surface.setResizable(true); // Allows the size of the window to be adjusted

  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);

  delay(100);
}
/*
*The following method draws the circle that imitates the inputs in the xy module
 
 */
void draw()
{
  background(122);
  lights();
  if (myPort.available()>0)
  {

    scan = new Scanner(myPort.readString());
    direction = (int)scan.nextInt();

    System.out.println(direction + "\n");
    myPort.clear();
  }
  pushMatrix();

  textSize(30);
  if (direction == 3)
    text("UP" + "\t", width/2, height);
  else if (direction == 4)
    text("DOWN"+  "\t", width/2, height);
  else if (direction == 2)
    text("LEFT" + "\t", width/2, height);
  else if (direction == 1)
    text("RIGHT" + "\t", width/2, height);
  delay(10);

  fill(255);
  noStroke();
  ellipse(xPos, yPos, 200, 200);
  stroke(0, 0, 255);
  //Right Direction
  if (direction ==1)
  {
    xPos+=addFactor;
    if (previousDirection == 1)
    {
      addFactor++;
    } else {
      addFactor =1;
    }
    fill(0);
    drawArrow(xPos, yPos, 170, 0);
    //Left Direction
  } else if (direction == 2)
  {
    xPos-=addFactor;
    drawArrow(xPos, yPos, 170, 180);
    if (previousDirection == 2)
    {
      addFactor++;
    } else {
      addFactor =1;
    }
    //Up direction
  } else if (direction == 3)
  {
    yPos-=addFactor;
    drawArrow(xPos, yPos, 170, 270);
    if (previousDirection == 3)
    {
      addFactor++;
    } else {
      addFactor =1;
    }
    //Down Direction
  } else if (direction == 4)
  {
    yPos+=addFactor;
    drawArrow(xPos, yPos, 170, 90);
    if (previousDirection == 4)
    {
      addFactor++;
    } else {
      addFactor =1;
    }
  }
  previousDirection = direction; //saves the previous direction, to compare if it duplicates later

  fill(180);

  popMatrix();
} 

/*
* The following method draws an arrow, has the following arguments.
 *    drawArrow(int xPosition, int yPosition, int length, int angle)
 *    
 *    angle- in degrees.
 */
void drawArrow(int cx, int cy, int len, float angle) {
  pushMatrix();
  translate(cx, cy);
  rotate(radians(angle));
  line(0, 0, len, 0);
  line(len, 0, len - 8, -8);
  line(len, 0, len - 8, 8);
  popMatrix();
}