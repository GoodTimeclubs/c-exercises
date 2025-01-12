#include <stdio.h>
#include <stdlib.h>
#include "readint.c"

struct Vektor {
    int x;
    int y;
    int z;
};

void printVektor(struct Vektor ausgabe)
{
    printf("Der Vektor lautet (%i,%i,%i)\n", ausgabe.x, ausgabe.y, ausgabe.z);
}

int main (){
    struct Vektor a;
    a.x = 1;
    a.y = -2;
    a.z = 3;
    printVektor(a);
}