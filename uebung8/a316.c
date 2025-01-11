#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
#include "a316.h"

int countArray (char* array) //Zählt die länge des Inputs
{
    int i = 0;
    while (array[i] != '\0')
    {
        i++;
    }
    return i;
}

int checkCopy(int inputsize, int coppos, int copcount) //Überprüft ob der Bereich innerhalb des Input strings liegt
{
    if ((coppos + copcount) > inputsize)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void copyData(char* input, int coppos, int copcount, char* output) //Koppiert den angegeben Bereich und gibt ihn aus
{
    int i = 0;

    for(i=0; i<copcount; i++)
    {
        output[i] = input[coppos+i];
    }

    output[i] = '\0';

    printf("Der kopierte Text lautet: \"%s\"\n", output);
}


void a316(char* input)
{
    int inputsize = 0;
    int coppos = 0;
    int copcount = 0;

    // Benutzereingabe
    printf("Von welcher Position soll koppiert werden?\n");
    scanf("%d", &coppos);
    printf("Wie viele Stellen sollen Koppiert werden?\n");
    scanf("%d", &copcount);

    char* output = malloc(copcount);

    inputsize = countArray(input);

    if (checkCopy(inputsize, coppos, copcount))
    {
        copyData(input, coppos, copcount, output);
        free(output);
    }
    else
    {
        printf("Der Angegebene Koppierbereich liegt ausserhalb der gegebenen Zeichenkette.\n");
        free(output);
    }
    
}