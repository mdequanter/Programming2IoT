#include <MemoryUsage.h>

String textValues[100];

void setup() 
{
    Serial.begin(115200);
    Serial.println(F("Starting state of the memory:"));
    Serial.println();
    
    MEMORY_PRINT_START
    MEMORY_PRINT_HEAPSTART
    MEMORY_PRINT_HEAPEND
    MEMORY_PRINT_STACKSTART
    MEMORY_PRINT_END
    MEMORY_PRINT_HEAPSIZE

    Serial.println();
    Serial.println();
   
    FREERAM_PRINT;

    byte *p = new byte[3000];    
    
    Serial.println();
    Serial.println();
    
    Serial.println(F("Ending state of the memory:"));
    Serial.println();
    
    MEMORY_PRINT_START
    MEMORY_PRINT_HEAPSTART
    MEMORY_PRINT_HEAPEND
    MEMORY_PRINT_STACKSTART
    MEMORY_PRINT_END
    MEMORY_PRINT_HEAPSIZE
    
    Serial.println();
    Serial.println();
    
    FREERAM_PRINT;
}

void loop() 
{
  for (int i = 0;i<=10000;i++) {
    int valuesPot2[i]={};
    
    Serial.println(F("*******************"));
    Serial.print(F("Pointers address : "));
    // print geheugenlocatie van valuesPot2
    Serial.println((long)&valuesPot2[0]);
    MEMORY_PRINT_HEAPSTART
    MEMORY_PRINT_HEAPSIZE      
    FREERAM_PRINT;  
    delay(50);
  }

}
