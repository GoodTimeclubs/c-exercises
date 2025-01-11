#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "readtext.h"
#define RAND_MAX 32

int checkOut (char* passwort)
{
    
    char upper = 0;
    char lower = 0;
    char number = 0;
    int i = 0;
    
    while(passwort[i] != '\0')
        {
            if (passwort[i] >= 'A' && passwort[i] <= 'Z'){ //Überprüfung ob Großbuchstabe
                upper = 1;
            }
            if (passwort[i] >= 'a' && passwort[i] <= 'z'){ //Überprüfung ob Kleinbuchstabe
                lower = 1;
            }
            if (passwort[i] >= '2' && passwort[i] <= '8'){ //Überprüfung ob Zahl
                number = 2;
            } 
            i++;
        }

    if(upper && lower && number)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main (){

    
    //festlegung des Pools der Zeichen
    char pool[33] = {'a', 'b', 'c', 'd', 'e', 'f', 'h', 'i', 'm', 'n', 'q', 'r', 't', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'L', 'M', 'N', 'Q', 'R', 'T', '2', '3', '4', '6', '7', '8'};
    int r = 0;
    int i = 0;

    //Initialisierung des Zufallsgenerators
    srandom(time(NULL));

    char* passwort = malloc(9);
    
    do
    {
        
        for (i=0; i<8; i++){
            r = random() % 33; //Zufallszahl zwischen 0 und 32
            passwort[i] = pool[r]; //Zufälliges Zeichen aus dem Pool
        }
        passwort[8] = '\0'; //Ende des Strings

    }while(checkOut(passwort)); //Überprüfung ob alle Bedingungen erfüllt sind

    //Ausgabe
    printf("Das generierte Passwort ist: %s\n", passwort);

    free(passwort);

    return 0;
}