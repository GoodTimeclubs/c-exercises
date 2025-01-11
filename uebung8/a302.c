#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
#include "a302.h"

char readchar()
{
    char out = 0;
    printf("Welches Zeichen soll gezaehlt werden?:\n");
    char *zeichen = readtext();
    out = zeichen[0];
    free(zeichen);
    return out;
}

void a302(char* text)
{
    unsigned int i = 0;
    unsigned int anzahl = 0;
    char zeichen;

    zeichen = readchar();

    while (text[i] != '\0')
    {
        if (text[i] == zeichen)
            anzahl++;
        i = i + 1;
    }

    printf("Die Eingabe enthaelt %d mal das Zeichen \"%c\".\n", anzahl, zeichen);
    
}