#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
#include "a314.h"

unsigned int findsmallest(unsigned int e1size, unsigned int e2size, unsigned int *compare)
{
    if (e1size <= e2size)
    {
        *compare = 1;
        return e1size;
    }
    else
    {
        *compare = 2;
        return e2size;
    }
}

void a314(char* eingabe1)
{
    // variablendeklaration
    unsigned int i = 0;
    unsigned int e1size = 0;
    unsigned int e1index = 0;
    unsigned int e2size = 0;
    unsigned int e2index = 0;
    unsigned int smallest = 0;
    unsigned int compare = 0; //gibt an, ob die 1. oder die 2. Eingabe kleiner ist

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

    smallest = findsmallest(e1size, e2size, &compare);

    // Definition der Ausgabevariable mit der exakt benötigten Größe
    char *ausgabe = malloc(e1size + e2size);

    // zusammenfüen der Zeihenketten
    while (i <= (smallest*2)) //solange beide Zeichenketten abwechselnd eingefügt werden können
    {

        if (e1index < e1size) // Buchstaben aus erstem String einfügen
        {
            ausgabe[i] = eingabe1[e1index];
            e1index++;
            i++;
        }

        if (e2index < e2size) // Buchstaben aus zweitem String einfügen
        {
            ausgabe[i] = eingabe2[e2index];
            e2index++;
        }

        i++;
    }

    if (compare == 2) // Wenn der 2. String kürzer ist, den rest des 1. Strings einfügen
    {
        while (i <= (e1size + e2size))
        {
            ausgabe[i] = eingabe1[e1index];
            e1index++;
            i++;
        }
    }

    if (compare == 1) //Wenn der 1. String kürzer ist, dem rest des 2. Strings einfügen.
    {
        while (i <= (e1size + e2size))
        {
            ausgabe[i] = eingabe2[e2index];
            e2index++;
            i++;
        }
    }

    //Beendung des Ausgabestrings
    ausgabe[i] = '\0';

    // Ausgabe
    printf("Vermischt ergibt das: \"%s\"\n", ausgabe);

    free(ausgabe);
    free(eingabe2);
}