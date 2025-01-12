#include <stdio.h>
#include <stdlib.h>
#include "readint.c"

struct Vektor 
{
    int x;
    int y;
    int z;
};

struct Vektor getVektor()
{
    struct Vektor eingabe;
    printf("Bitte geben sie den Wert des Vektors für x ein:");
    eingabe.x = readint();
    printf("Bitte geben sie den Wert des Vektors für y ein:");
    eingabe.y = readint();
    printf("Bitte geben sie den Wert des Vektors für z ein:");
    eingabe.z = readint();

    return eingabe;
}

void printVektor(struct Vektor ausgabe)
{
    printf("Der Vektor lautet (%i,%i,%i)\n", ausgabe.x, ausgabe.y, ausgabe.z);
}

int main ()
{
    struct Vektor a;
    
    a = getVektor();

    printVektor(a);
}