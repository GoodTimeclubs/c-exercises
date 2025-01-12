#include <stdio.h>

int main (){

    int zahl = 5; //Schleifeninitialisierung
    int zahl2 = 5;
    
    while (zahl > 0){ //Bedingung
        printf("zahl = %d\n", zahl);
        zahl = zahl - 1; // Zählen
    }

    for (int i = 5; i > 0; i--){
        printf("i = %d\n", i);        
    }

    do{
        // zuerst ausführen
        printf("zahl2 = %d\n", zahl2);
        zahl2 = zahl2- 1; // Zählen

    } while (zahl2 > 0); // dann Bedingung überprüfen
    

    return 0;
}