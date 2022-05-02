/***********************************************************
File name: inputNaarServo.ino
Description: Inlezen van analoge waarden en de servo's instellen op deze gemapte waarde
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

/*
Eerste stellen we alles in.  We zorgen voor het configureren van de in of uitgangspinnen, stellen de servo's in 
en schrijven ineens de juiste waarde(angle) naar de servo objecten waardoor de servo's in de juiste stand gaan staan.
*/

void setup() {
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
Deze loop is leeg omdat we slechts 1 maal een initialisatie van de servo's moeten doen.
*/

void loop()
{
  
  // Lezen van waarden van potentiometer en mappen naar een servo waarde.
  
  val1 = map(analogRead(0), 0, 1023, 0, 180);  
  val2 = map(analogRead(1), 0, 1023, 0, 180);  
  val3 = map(analogRead(2), 0, 1023, 0, 180);  
  val4 = map(analogRead(3), 0, 1023, 0, 180);
  val5 = map(analogRead(6), 0, 1023, 35, 90);

  // Schrijven naar servo object
  
  servo1.write(val1);
  servo2.write(val2);
  servo3.write(val3);
  servo4.write(val4);
  servo5.write(val5); 

  // kleine pauze om de servo's toe te laten zich te verplaatsen.
  delay(20);
}
