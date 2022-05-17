/***********************************************************
Description: Demo gebruik van geheugen locaties in een array en verwijzen naar geheugenlocatie via pointer.
Author: Maarten Dequanter
Date: 17/05/2022
***********************************************************/
int lijstInt[10];
double lijstDouble[10];


void setup()
{
  Serial.begin(115200);
  
  Serial.print("Integer lijst adressen :");
  
  for (int i = 0; i<=9; i++) {
    lijstInt[i] = 1;
    Serial.print(" ");
    Serial.print((long)&lijstInt[i]);
  }
  
  Serial.println("");
  Serial.println("*********************");
  
  
  Serial.print("Integer lijst adressen :");
  
  for (int i = 0; i<=9; i++) {
    lijstDouble[i] = 2;
    Serial.print(" ");
    Serial.print((long)&lijstDouble[i]);
  }

  Serial.println("");
  Serial.println("*********************");
  

  int *pAdres;
  pAdres = &lijstInt[3];
  
  *pAdres = 5;
  
  Serial.print("Nieuwe inhoud integer lijst :");
  
  for (int i = 0; i<=9 ; i++) {
    Serial.print(" ");
    Serial.print(lijstInt[i]);
  }
  
  
}

void loop()
{
  
}              
