#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(4);

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.display();
}

void loop() {
  display.clearDisplay();
  delay(200);
//display.drawLine(0,0,display.width() - 1, display.height() - 1, WHITE);
//display.drawLine(display.width() - 1,0,0, display.height() - 1, WHITE);

display.setTextColor(WHITE);
display.setCursor(35,10);
display.println("Hello World!");
display.display();
}
