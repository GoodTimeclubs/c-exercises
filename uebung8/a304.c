#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
#include "a304.h"

void a304 (char *eingabe){
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
    printf("Der Gespiegelte text ist: %s\n", eingabeMirror);

    free(eingabeMirror);
}