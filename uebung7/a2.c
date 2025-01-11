#include <stdio.h>

int eineZahl(){
    int eingabe = 0;
    printf("Bitte geben sie eine ganze Zahl ein: ");
    scanf("%i", &eingabe);
    return eingabe;
}

void ausgabeZahlen(int zahl1, int zahl2){
    printf("Deine Zahlen waren %i und %i.\n", zahl1, zahl2);
}

void zweiZahlen(int* zahl1, int* zahl2){
    *zahl1 = eineZahl();
    *zahl2 = eineZahl(); 
    ausgabeZahlen(*zahl1, *zahl2);
}

void ausgabeSumme(int summe){
    printf("Die Summe ist %d.\n", summe);

}

int Summe(int zahl1, int zahl2){
    int summe = zahl1 + zahl2;
    ausgabeSumme(summe);
    return summe;
}

int main (){
    int zahl1 = 0;
    int zahl2 = 0;

    zweiZahlen(&zahl1, &zahl2);
    Summe(zahl1, zahl2);
}