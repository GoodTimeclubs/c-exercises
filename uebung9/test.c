#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"
#include "readint.c"

int main (){
    printf("Bitte geben Sie eine Zahl ein:\n");
    int zahl = readint();
    printf("Deine Zahl war: %d\n", zahl);
}