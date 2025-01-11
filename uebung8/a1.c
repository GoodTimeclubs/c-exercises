#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"

int main(){
    printf("Bitte geben sie einen Text ein:\n");
    char* text = readtext();
    printf("Eingegebener Text war: %s\n", text);
    free(text);
}

