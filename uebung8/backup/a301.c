#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"

int a301 ()
{
    unsigned i = 0;
    printf("Bitte geben sie einen Text ein:\n");
    char* text = readtext();
    while (text[i] != '\0')
    {
        i = i+1;
    }

    printf("Der Text ist %d Zeichen lang.\n", i);
    free(text);
}