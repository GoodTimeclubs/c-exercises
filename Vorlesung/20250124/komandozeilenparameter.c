#include <stdio.h>
#include <stdlib.h>


int main (int anzahl, char** parameter){
    int i = 0;
    printf("Dieses Programm wurde mit %d parametern aufgerufen.\n", anzahl);
    for(i=0; i<anzahl; i++){
        printf("Der %d. Parameter hat den Wert \"%s\"\n", i+1, parameter[i]);
    }

    return 0;
}