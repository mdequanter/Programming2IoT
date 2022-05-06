/***********************************************************
Description: Optimalisate van code gebruik van functies, verschillende servo posities na elkaar om een object te verplaatsen.
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

int counter = 0;

int servo1Pos=90;
int servo2Pos=90;
int servo3Pos=90;
int servo4Pos=90;
int servo5Pos=90;

int servo1Lijst[5] = {90,180,0,180,90};
int servo2Lijst[5] = {90,50,50,90,90};
int servo3Lijst[5] = {90,90,170,90,90};
int servo4Lijst[5] = {90,90,90,90,90};
int servo5Lijst[5] = {90,35,35,90,90};


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
* Functie om op een degelijke snelheid van de ene naar de ander positie te gaan
*/

void servoPos(Servo servo, int pos1, int pos2) {
  Serial.print(pos1); Serial.print("->");Serial.print(pos2);
  if (pos1 < pos2) {
    for (int i=pos1; i<=pos2; i++) {
      servo.write(i);
      delay(20);
      Serial.print(".");
    }
  }
  if (pos1 > pos2) {
    for (int i=pos1; i>=pos2; i--) {
      servo.write(i);
      delay(20);
      Serial.print(".");
    }
  }
  Serial.println(".");
}

void servosToPos(int step) {
  if (servo1Pos != servo1Lijst[step]) {
    servoPos(servo1,servo1Pos,servo1Lijst[step]);
    servo1Pos = servo1Lijst[step];
  }
  if (servo2Pos != servo2Lijst[step]) {
    servoPos(servo2,servo2Pos,servo2Lijst[step]);
    servo2Pos = servo2Lijst[step];
  }
  if (servo3Pos != servo3Lijst[step]) {
    servoPos(servo3,servo3Pos,servo3Lijst[step]);
    servo3Pos = servo3Lijst[step];
  }
  if (servo4Pos != servo4Lijst[step]) {
    servoPos(servo4,servo4Pos,servo4Lijst[step]);
    servo4Pos = servo4Lijst[step];
  }
  if (servo5Pos != servo5Lijst[step]) {
    servoPos(servo5,servo5Pos,servo5Lijst[step]);
    servo5Pos = servo5Lijst[step];
  } 
}

/*
 * Functie om het aantal itteraties weer te geven.
 */

void weergevenRuns() {
  Serial.print("Aantal runs: ");
  Serial.println(counter);
}


void loop()
{
  for (int i = 0; i<=4; i++) {
      servosToPos(i);   
  }
  

  


}
