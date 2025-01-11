#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
#include "a306.h"

void a306 (char* eingabe){
    unsigned int elaenge = 0;
    unsigned int i = 0;

    //Berechnung der Stringlänge
    while(eingabe[elaenge] != '\0')
    {
        elaenge++;
    }

    //Definition der neuen Variable
    char* eingabeMirror = malloc (elaenge);
    
    //Befüllen der neuen Variable in gespiegelter Reihenfolge
    for (i = 0; i < elaenge; i++){
        eingabeMirror[i] = eingabe[elaenge -1 - i]; //-1, damit das '\0' nicht an den Anfang des neuen Strings übernommen wird 
    }

    eingabeMirror[elaenge] = '\0';

    //Ausgabe der neuen Variable
    printf("Das Palindrom ist: %s%s\n", eingabe, eingabeMirror); //veränderte Ausgabe um Palindrom darzustellen

    free(eingabeMirror);
}