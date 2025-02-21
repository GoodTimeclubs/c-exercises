#include <stdio.h>
#include "../tools/readint.c"

int main () {

    char z[12];
    int i = 0;

    for (i = 0; i < 12; i++){
        printf("Bitte geben Sie eine Zahl ein: \n");
        z[i]=readint();
    }

    for (i = 0; i < 12; i++){
        printf("%c", z[i]);
    }

    return 0;
}