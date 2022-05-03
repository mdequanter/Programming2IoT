/***********************************************************
Description: Recursieve functies, voer een servo procedurefunctie uit zolang er niet op een button wordt gedrukt.
Author: Maarten Dequanter
Date: 02/05/2022
***********************************************************/

// We laden de standaard arduino bibliotheek
#include <Servo.h>

// Initialisatie van servo aansluitingen
int servopin1 = 9;    //Servo 1 is verbonden met digitale poort 9
int servopin2 = 6;    
int servopin3 = 5;    
int servopin4 = 3;    
int servopin5 = 11; 
int buttonPin = 4;  

// Initialisatie van Servo objecten 1 object per servo.
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// declareren en initiëliseren van basiswaarden potentiometers
 
int val1=90;//Variabele voor opslaan waarde van analoge ingang 1
int val2=90;
int val3=90;
int val4=90;
int val5=90;


// declareren en initialiseren van  globale variabelen

int counter = 0;
bool programmaIsRunning = false; // aanduiden of programma mag lopen.
bool done = false; // aanduiden of huidige servo actie(ServoPos functie) is afgerond.


/*
Eerste stellen we alles in.  We zorgen voor het configureren van de in of uitgangspinnen, stellen de servo's in 
en schrijven ineens de juiste waarde(angle) naar de servo objecten waardoor de servo's in de juiste stand gaan staan.
*/

void setup() {
  Serial.begin(115200);
  pinMode(servopin1,OUTPUT);//Pin instellen als output.
  pinMode(servopin2,OUTPUT);
  pinMode(servopin3,OUTPUT);
  pinMode(servopin4,OUTPUT);
  pinMode(servopin5,OUTPUT);
  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);
  servo5.attach(servopin5);
  
  servo1.write(val1);  // initiële stand instellen
  servo2.write(val2);
  servo3.write(val3);
  servo4.write(val4);
  servo5.write(val5); 
}

/*
* Functie om op een degelijke snelheid van de ene (pos1) naar de ander positie(pos2) te gaan
* Hierbij geven we steeds een servo object mee, zodat we dezelfde functie kunnen gebruiken voor alle servo's
* Wanneer pos1 == pos2 werd de itteratie afgerond en pas dan is return = true.
*/

bool servoPos(Servo servo, int pos1, int pos2) {
  
  buttonPressed(buttonPin);

  if (programmaIsRunning == true) {    
    if (pos1 < pos2) {
      pos1++;
      servo.write(pos1);
      delay(100);
    }
    if (pos1 > pos2) {
      pos1--;
      servo.write(pos1);
      delay(100);
    }
  }

  if (pos1!=pos2) {
    // recursieve functieaanroep.  Servo1Pos steeds herhalen zolang programma mag lopen(button) 
    // én zolang eindpositie(pos2) niet is bereikt
    servoPos(servo,pos1,pos2);
  } else {
    return true;
  }
}

void buttonPressed(int buttonPin) {
  if(digitalRead(buttonPin)==LOW){
    delay(500);
    if (programmaIsRunning == true){
      programmaIsRunning = false;
    } else {
      programmaIsRunning = true;
    }
  }
}


/*
 * Servo1 draaien naar van beginpositie(90) naar 180
 * Daarna servo 2 van beginpositie(90) naar beneden(30)
 * Servo1 terug draaien naar beginpositie (90)
 * Servo2 terug naar boven(90)
 */
void loop()
{
  done = servoPos(servo1,90,180);
  // enkel indien de servo1 van positie 90 naar 180 is gegaan, kunnen we verder.
  if (done == true) {
    done = servoPos(servo2,90,30);
    if (done == true) {
      done = servoPos(servo1,180,90);
      if (done == true) {
        done = servoPos(servo2,30,90);
      }
    }
  }
}
