#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
#include "a313.h"


void a313(char* eingabe1)
{
    // variablendeklaration
    unsigned int i = 0;
    unsigned int e1size = 0;
    unsigned int e2size = 0;


    // Benutzereingabe
    printf("Bitte geben Sie die zweite Zeichenkette ein:\n");
    char *eingabe2 = readtext();

    // Berechnung der länge der 1. Eingabe
    while (eingabe1[e1size] != '\0')
    {
        e1size++;
    }

    // Berechnung der länge der 2. Eingabe
    while (eingabe2[e2size] != '\0')
    {
        e2size++;
    }

    //Definition der Ausgabevariable mit der exakt benötigten Größe
    char* ausgabe = malloc(e1size+e2size);
    
    //zusammenfüen der Zeihenketten
    while (i <= (e1size+e2size))
    {
        if (i < e1size) //nicht <=, damit '\0' nicht mit übernommen wird
        {
            ausgabe[i] = eingabe1[i]; // erster String wird in Ausgabe übernommen
        }
        else
        {
            ausgabe[i] = eingabe2[i-e1size]; // die Länge des ersten Strings wird von dem Inderx für eingabe2 abgezogen, damit dieser bei 0 angefangen wird einzulesen.
        }
        i++;
    }

    //Ausgabe
    printf("Zusammengefuegt ergibt das: \"%s\"\n", ausgabe);
    
    free(ausgabe);
    free(eingabe2);
}