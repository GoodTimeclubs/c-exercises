#include <stdio.h>

int main (int anzahl, char** dateiname){
    if (anzahl != 3){
        //fputs("Bitte geben Sie die Argumente in dem folgenden Format an\n<source> <destination>\n", stdout); //in output datei schreiben
        fputs("Bitte geben Sie die Argumente in dem folgenden Format an\n<source> <destination>\n", stderr); //in output datei schreiben als Fehler
        return 1;
    }

    FILE* src = fopen(dateiname[1],"rb"); //mit b erweitert um Binär zu arbeiten
    if (src == NULL){
        fputs("Die Quelldatei konnte nicht geöffnet werden\n", stderr); //in output datei schreiben als Fehler
        return 2;
    }

    FILE* dest = fopen(dateiname[2],"wb");
    if (dest == NULL){
        fputs("Die Zieldatei konnte nicht zum schreiben geöffnet werden\n", stderr); //in output datei schreiben als Fehler
        fclose(src);
        return 3;
    }

    char byte;
    while ((byte = fgetc(src)) != EOF)
    {
        fputc(byte, dest);
    }
    

    fclose(src);
    fclose(dest);

    return 0;
}
