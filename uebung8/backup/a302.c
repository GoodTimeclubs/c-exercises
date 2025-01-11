#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"

char readchar()
{
    unsigned i = 0;
    printf("Welches Zeichen soll gezaehlt werden?:\n");
    char *zeichen = readtext();
    
    while (zeichen[i] != '\0')
    {
        i++;
    }

    return zeichen[0];
}

int a302()
{
    unsigned int i = 0;
    unsigned int anzahl = 0;
    char zeichen;
    printf("Bitte geben sie einen Text ein:\n");
    char *text = readtext();
    zeichen = readchar();

    while (text[i] != '\0')
    {
        if (text[i] == zeichen)
            anzahl++;
        i = i + 1;
    }

    printf("Der Text enthaelt %d mal das Zeichen \"%c\".\n", anzahl, zeichen);
    
    free(text);
    
    return 0;
}