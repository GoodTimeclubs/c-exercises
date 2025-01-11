#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
#include "a305.h"

void a305 (char* eingabe){

    unsigned int i = 0;
    unsigned int esize = 0;

    //Berechnung des benötigten Speicherplatzes
    while (eingabe[esize] != '\0'){
        esize++;
    }

    //Speicherreservierung einer neuen Variable und damit an einem neuen Speicherplatz.
    char* eingabe2 = malloc(esize);

    //Kopieren des Inhalts in die neue Variable
    while (eingabe[i] != '\0'){
        eingabe2[i] = eingabe[i] + 1; //Verschiebung des Ascii Zeichens um 1
        i++;
    }

    //setzen des Ende des Strings für eine korrekte Ausgabe
    eingabe2[i] = '\0';


    printf("Die Eingabe wurde zu:\n%s\n", eingabe2);

    free (eingabe2);
}