#include <stdio.h>
#include <stdlib.h>
#include "readint.c"

int main (){
    printf("Bitte geben Sie eine Zahl ein: \n");
    int eingabe = readint();
    printf("Deine eingegebene Zahl war %i\n", eingabe);
}