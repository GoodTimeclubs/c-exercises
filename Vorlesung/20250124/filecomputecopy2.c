#include <stdio.h>
#include <stdlib.h>
#include"../../tools/readtext.c"

int main (int argc, char** argv){
    FILE* datei;//referenziert auf Datei
    char content[100];
    int i = 0;
    datei = fopen("dateien.txt", "r"); //fopen = fileopen | w für write | r für read | a für append also anhängen
    if (datei != NULL){
        
        fgets(content, sizeof(content), datei);//file get string | einlesen der ersten Zeile
        
        printf("%s\n", content); //ausgabe der ersten Zeile
        
        fclose(datei);
    }
    return 0;
}