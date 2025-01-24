#include <stdio.h>
#include <stdlib.h>
#include"../../tools/readtext.c"

// aufruf mit ./filecompute.x < eingabe.txt
// Tastatureingabe wird emuliert
// aufruf mit Ausgabe in neuer Datei ./filecompute.x < eingabe.txt > ausgabe.txt
// aufruf mit Ausgabe in Datei aber vorheriger inhalt wird behalten ./filecompute.x < eingabe.txt > ausgabe.txt
int main (){
    char* eins = readtext();
    char* zwei = readtext();
    char* drei = readtext();
    printf("Erste Zeile %s\n", eins);
    printf("Zweite Zeile %s\n", zwei);
    printf("Dritte Zeile %s\n", drei);
    return 0;
}