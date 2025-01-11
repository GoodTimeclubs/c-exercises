#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
#include "a312.h"

int checkeven(char *eingabe1, char *eingabe2)
{
    unsigned int i = 0;
    while (eingabe1[i] != '\0')
    {
        if (!(eingabe1[i] == eingabe2[i])) // Überprüfung ob alle Buchstaben gleich sind
        {
            return 1;
        }
        i++;
    }

    if (eingabe2[i] == '\0') // überprüfung ob auch eingabe2 am string ende ist
    {
        printf("\"%s\" ist identisch zu \"%s\"\n", eingabe1, eingabe2);
        return 0;
    }
    else
        return 1;
}

void a312(char* eingabe1)
{
    // variablendeklaration
    unsigned int i = 0;
    unsigned int e1size = 0;
    unsigned int e2size = 0;
    unsigned int smallest = 0;
    unsigned int stop = 0;

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

    // finden der kürzeren eingabe
    if (e1size <= e2size)
    {
        smallest = e1size;
    }
    else
    {
        smallest = e2size;
    }

    // überprüfen ob Eingaben gleich sind
    if (checkeven(eingabe1, eingabe2))
    {
        do // buchstabenweises Überprüfen welche Eingabe kleiner ist
        {
            if (eingabe1[i] < eingabe2[i])
            {
                printf("\"%s\" ist alphabetisch kleiner als \"%s\"\n", eingabe1, eingabe2);
                stop = 1;
            }
            else if (eingabe1[i] > eingabe2[i])
            {
                printf("\"%s\" ist alphabetisch kleiner als \"%s\"\n", eingabe2, eingabe1);
                stop = 1;
            }
            i++;
        } while (i <= smallest && stop == 0);
    }
    free(eingabe2);
}