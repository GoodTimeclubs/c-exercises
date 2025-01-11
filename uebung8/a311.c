#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
#include "a311.h"

void a311 (char* eingabe){

    unsigned int i = 0;
    unsigned int esize = 0;
    
    unsigned int faktor = 0;
    
    printf ("Um welchen positiven Faktor soll verschoben werden?\n");
    scanf ("%d", &faktor);
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

        eingabe2[i] = eingabe[i] + faktor; //addieren edes Faktors

        // Überprüfung ob Ergebnis außerhalb des Alphabets liegt
        while (!((eingabe2[i] >= 'a' && eingabe2[i] <= 'z') || (eingabe2[i] >= 'A' && eingabe2[i] <= 'Z')))
        {
            //Verschiebung des Wertes in den Bereich des Alphabets
            eingabe2[i] = eingabe2[i] - 26;

        }
        
        i++;
    }

    //setzen des Ende des Strings für eine korrekte Ausgabe
    eingabe2[i] = '\0';

    printf("Die mit dem Faktor %d verschluesselte Eingabe lautet:\n%s\n",faktor, eingabe2);

    free (eingabe2);
}