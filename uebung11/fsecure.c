#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tools/readtext.c"
#include "../tools/readint.c"

enum Bool {FALSE,TRUE};

char* get_password(){
    printf("Bitte geben Sie das Passwort ein");
    char* pw1 = readtext();
    return pw1;
}

int main(int argc, char** argv){
    FILE* dest;
    FILE* src;
    char byte;
    char* password;
    unsigned int pw_i = 0;
    int i_encrypt = 0;
    int i_decrypt = 0;
    int i_output = 0;

    //Parameter einlesen
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--encrypt") == 0 || strcmp(argv[i], "-e") == 0) {
            i_encrypt = i;
        }
        if (strcmp(argv[i], "--decrypt") == 0 || strcmp(argv[i], "-d") == 0) {
            i_decrypt = i;
        }
        if (strcmp(argv[i], "--output") == 0 || strcmp(argv[i], "-o") == 0) {
            i_output = i;
        }
    }

    printf("DEBUG - encrypt:%d decrypt:%d output:%d\n",i_encrypt, i_decrypt, i_output);

    if(i_encrypt && i_decrypt)
    {
        fputs("ERROR - <--encrypt|-e> und <--decrypt|-d> drüfen nicht gelichzeitig verwendet werden!\n", stderr);
        return 1;
    }
    //Input file
    if(argv[1] != argv[i_encrypt] && argv[1] != argv[i_decrypt] && argv[1] != argv[i_output]){
        src = fopen("input.txt", "rb");
        if(src == NULL)
        {
            fputs("Die Quelldatei konnte nicht geöffnet werden.\n", stderr);
            return 2;
        }
    }
    
    if(i_output == 0){//wenn keine Output datei angegeben wurde
        fputs("Bitte gib eine Ausgabedatei mit dem Parameter <--output|-o> \"DATEINAME\" an!\n", stderr);
            return 3;
    } else {
        if(i_output+1 < argc){//wenn Output Datei angegeben wurde
            dest = fopen(argv[i_output+1],"wb"); //Parameter nach -o oder --output als Ausgabedatei einlesen
            if(dest == NULL)
            {
                fputs("Die Ausgabedatei konnte nicht geöffnet oder erstellt werden.\n", stderr);
                fclose(src);
                return 4;
            }
        } else {
            fputs("Es wurde keine Ausgabedatei hinter <--output|-o> angegeben!\n", stderr);
            return 5;
        }
    }

    //einlesen des Passworts
    password = get_password();

    //Datei verarbeiten und in output schreiben
    while((byte = fgetc(src)) != EOF)
    {
        if (password[pw_i] == '\0') pw_i = 0;
        
        if(i_encrypt) byte = byte + password[pw_i];
        if(i_decrypt) byte = byte - password[pw_i];

        fputc (byte, dest);
        pw_i ++;
    }

    fclose(src);
    fclose(dest);
}