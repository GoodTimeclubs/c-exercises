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
    struct Vektor b;
    struct Vektor c;

    a.x = 1;
    a.y = -2;
    a.z = 3;

    b.x = 1;
    b.y = -2;
    b.z = 3;

    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;

    printVektor(c);
}