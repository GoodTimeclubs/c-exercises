#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
#include "a301.h"

void a301 (char* text)
{
    unsigned i = 0;
    while (text[i] != '\0')
    {
        i = i+1;
    }

    printf("Die Eingabe ist %d Zeichen lang.\n", i);
}
