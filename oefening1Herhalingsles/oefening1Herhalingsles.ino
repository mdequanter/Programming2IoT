/*
Eerste stellen we alles in.  We zorgen voor het configureren van de in of uitgangspinnen, stellen de servo's in 
en schrijven ineens de juiste waarde(angle) naar de servo objecten waardoor de servo's in de juiste stand gaan staan.
*/
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
int angle = 90;        //Variabele om servo's in te stellen


void setup() {
  // put your setup code here, to run once:
  pinMode(servopin1,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin2,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin3,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin4,OUTPUT);//Set the servo interface as the output interface
  pinMode(servopin5,OUTPUT);//Set the servo interface as the output interface
  servo1.attach(servopin1);
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);
  servo5.attach(servopin5);
  servo1.write(angle);
  servo2.write(angle);
  servo3.write(angle);
  servo4.write(angle);
  servo5.write(angle); 
}

/*
reeks = reeks 1, 2 of 3
*/

void setServos(int reeks, int value) {
  
  if (reeks == 1) {
    servo1.write(value);
    servo2.write(value);
  }
  if (reeks == 2) {
    servo3.write(value);
    servo4.write(value);
  }
  if (reeks == 3) {
    servo5.write(value);
  }
  delay(20);
}

/*
Deze loop is leeg omdat we slechts 1 maal een initialisatie van de servo's moeten doen.
*/

void loop(){
    int AnalogInput1_2 = map(analogRead(0), 0, 1023, 45, 135);
    int AnalogInput3_4 = map(analogRead(1), 0, 1023, 135, 180);
    int AnalogInput5 = map(analogRead(2), 0, 1023, 0, 90);
    
    setServos(1, AnalogInput1_2);
    setServos(2, AnalogInput3_4);
    setServos(3, AnalogInput5);
}
