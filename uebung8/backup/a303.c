#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"

int a303 (){

    unsigned int i = 0;
    unsigned int esize = 0;
    
    //Benutzereingabe
    printf ("Bitte geben Sie einen Text ein\n");
    char* eingabe = readtext();
    
    printf ("Die Eingabe wurde an der Adresse %p gespeichert.\n", eingabe);

    //Berechnung des benötigten Speicherplatzes
    while (eingabe[esize] != '\0'){
        esize++;
    }

    //Speicherreservierung einer neuen Variable und damit an einem neuen Speicherplatz.
    char* eingabe2 = malloc(esize);

    //Kopieren des Inhalts in die neue Variable
    while (eingabe[i] != '\0'){
        eingabe2[i] = eingabe[i];
        i++;
    }

    //setzen des Ende des Strings für eine korrekte Ausgabe
    eingabe2[i] = '\0';

    //löschen der ersten Variable, da diese nicht mehr benötigt wird
    free (eingabe);

    printf("Die Eingabe wurde auf die Adresse %p verschoben.\n", eingabe2);
    printf("Deine Eingabe war:\n%s\n", eingabe2);

    free (eingabe2);

    return 0;
}