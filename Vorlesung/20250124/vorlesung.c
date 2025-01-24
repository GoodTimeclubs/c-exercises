#include <stdio.h>
#include <stdlib.h>

//aufzähungen
enum NOTE{SEHRGUT, GUT, BEFRIEDIGEND, AUSREICHEND, PECHGEHABT};

int main (){
    enum NOTE klausurergebnis;
    klausurergebnis = SEHRGUT;
    if (klausurergebnis == SEHRGUT){
        printf("Toll gemacht du kek\n");
    } else if (klausurergebnis == GUT){
        printf("Klasse...\n");
    } else {
        printf("mehr lernen!\n");
    }
    printf("wert = %d\n", klausurergebnis);
    return 0;
}