#include <stdio.h>
#include <stdlib.h>
#include"../../tools/readtext.c"

int main (){
    FILE* datei;//referenziert auf Datei
    datei = fopen("dateien.txt", "a"); //fopen = fileopen | w für write | r für read | a für append also anhängen
    fputs("hallo Welt\n", datei);
    fputs("zweite Zeile\n", datei);
    fputs("dritte Zeile\n", datei); //file put string
    fputc('X',datei); //file put char
    fclose(datei); //Speichert Änderungen
    return 0;
}