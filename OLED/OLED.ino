 /*************************************
File name:OLED
Description: Gebruik van extra bibliotheken, extern oled scherm
Author: Maarten Dequanter
Date: 02/05/2022
*************************************/
// seriële communicatie over de IC2 bus.
#include <Wire.h>
// Adafruit code grafische bibliotheek
#include <Adafruit_GFX.h>

// Bibliotheek voor monochroom cherm
#include <Adafruit_SSD1306.h>


#define OLED_RESET     4

// initialiseren van object op basis van bibliotheek
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);
int oldA0 = 0;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);//Sets the font display color
  display.clearDisplay(); // display buffer leeg maken
}

void loop() {
  int val1 = map(analogRead(0), 0, 1023, 0, 180); 
  if (val1 !=oldA0) {
    display.clearDisplay(); // display buffer leeg maken
    display.display(); // weergeven van display buffer, in dit geval leeg. Dus leeg scherm.
  }
  //tekst grootte instellen
  display.setTextSize(2);
  //Positie op display fixeren
  display.setCursor(0,0);
  //Text naar display buffer printen
  display.print("value:");
  display.setCursor(0,20);
  oldA0 = val1;
  display.print(val1);
  // display buffer weergeven, dus waarden val1
  display.display();
}
