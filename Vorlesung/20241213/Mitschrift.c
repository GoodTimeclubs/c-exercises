#include <stdio.h>

int produkt (int x, int y){
    
    int ergebnis = x*y; // Variable nur in Funktion

    return ergebnis;
}

double fakeMain () {
    return 23.76;

}

int liesZahlEin (void){
    int eingabe = 0;
    printf("Bitte Zahl: ");
    scanf("%i", &eingabe);
    
    return eingabe;
}

void Ausgabe (int wert){

    printf("%i\n", wert);

}

int main () {

    int zahl1 = 4;
    int zahl2 = liesZahlEin();
    int ausgabe = 0;

    ausgabe = produkt(zahl1, zahl2);

    Ausgabe(ausgabe);

    return 0;
}



