#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
#include "a310.h"

void a310 (char* eingabe){

    unsigned int i = 0;
    unsigned int esize = 0;
    
    //Berechnung des benötigten Speicherplatzes
    while (eingabe[esize] != '\0')
    {
        esize++;
    }

    //Speicherreservierung einer neuen Variable und damit an einem neuen Speicherplatz.
    char* eingabe2 = malloc(esize);

    //Kopieren des Inhalts in die neue Variable
    while (eingabe[i] != '\0')
    {
        //falls Großbuchstabe
        if(eingabe[i] >= 'A' && eingabe[i] <= 'M') //wenn im vorderen Teil des Alphabets
        {
            eingabe2[i] = eingabe[i] +13; //verschiebung in den hinteren teil des Alphabets
        }
        else if (eingabe[i] >= 'N' && eingabe[i] <= 'Z') //wenn im hinteren Teil des Alphabets
        {
            eingabe2[i] = eingabe[i] -13; //verschiebung in den vorderen teil des Alphabets
        }

        //falls Kleinbuchstabe (logische vorgehensweise identisch zu Großbuchstaben)
        if(eingabe[i] >= 'a' && eingabe[i] <= 'm') 
        {
            eingabe2[i] = eingabe[i] +13; 
        }
        else if (eingabe[i] >= 'n' && eingabe[i] <= 'z')
        {
            eingabe2[i] = eingabe[i] -13;
        }

        i++;
    }

    //setzen des Ende des Strings für eine korrekte Ausgabe
    eingabe2[i] = '\0';

    printf("Die mit ROT13 verschluesselte Eingabe lautet:\n%s\n", eingabe2);

    free (eingabe2);
}