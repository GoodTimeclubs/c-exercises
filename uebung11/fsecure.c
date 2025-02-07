#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../tools/readtext.c"
#include "../tools/readint.c"

enum Bool {FALSE,TRUE};

char* get_password(){
    int pwlength = 0;
    int i = 0;
    char* tpw1;
    char* pw1;
    char* pw2;
    tpw1=getpass("Bitte geben Sie das Passwort ein:");


    while(tpw1[pwlength] != '\0'){
        pwlength++;
    }

    pw1 = malloc(pwlength+1*sizeof(char));

    i = 0;
    while(tpw1[i] != '\0'){
        pw1[i] = tpw1[i];
        i++;
    }
    pw1[pwlength] = '\0';

    pw2=getpass("Bitte geben Sie das Passwort erneut ein:");

    i = 0;
    while(pw1[i] != '\0'){
        if(pw1[i] != pw2[i]){
            fputs("Die zwei Passwörter waren nicht Identisch!\n", stderr);
            free(pw1);
            exit(10);
        }
        i++;
    }
    i = 0;
    while(pw2[i] != '\0'){
        if(pw1[i] != pw2[i]){
            fputs("Die zwei Passwörter waren nicht Identisch!\n", stderr);
            free(pw1);
            exit(10);
        }
        i++;
    }


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
    } else if (!i_encrypt && !i_decrypt) {
        fputs("ERROR - bitte geben Sie entweden <--encrypt|-e> oder <--decrypt|-d> als Parameter an!\n", stderr);
        return 1;
    }



    //Input file
    if(argv[1] != argv[i_encrypt] && argv[1] != argv[i_decrypt] && argv[1] != argv[i_output]){
        src = fopen(argv[1], "r");
        if(src == NULL)
        {
            fputs("Die Quelldatei konnte nicht geöffnet werden.\n", stderr);
            return 2;
        }
    } else {
        fputs("Bitte gib eine Eingabedatei als ersten Parameter an!\n", stderr);
        return 4;
    }
    

    //Output file
    if(i_output == 0){//wenn keine Output datei angegeben wurde
        fputs("Bitte gib eine Ausgabedatei mit dem Parameter <--output|-o> \"DATEINAME\" an!\n", stderr);
        fclose(src);
        return 5;
    } else {
        if(argv[i_output+1] == argv[i_encrypt] && argv[i_output+1] != argv[i_decrypt]){
            fputs("Es wurde keine Ausgabedatei hinter <--output|-o> angegeben!\n", stderr);
            fclose(src);
            return 7;
        }
        else if(i_output+1 < argc){//wenn Output Datei angegeben wurde
            dest = fopen(argv[i_output+1],"w"); //Parameter nach -o oder --output als Ausgabedatei einlesen
            if(dest == NULL)
            {
                fputs("Die Ausgabedatei konnte nicht geöffnet oder erstellt werden.\n", stderr);
                fclose(src);
                return 6;
            }
        }    
    }

    //einlesen des Passworts
    password = get_password();
    //Datei verarbeiten und in output schreiben
    while((byte = fgetc(src)) != EOF)
    {
        if (password[pw_i] == '\0') {
            pw_i = 0;
            }
        
        if(i_encrypt) 
        {
            byte = byte + password[pw_i];
        }
        if(i_decrypt)
        {
            byte = byte - password[pw_i];
        }
        fputc (byte, dest);
        pw_i ++;
    }

    //Ausgabe
    if(i_encrypt){
        printf("Die Verschlüsselung wurde abgeschlossen.\n");
    }
    else if(i_decrypt){
        printf("Die Entschlüsselung wurde abgeschlossen.\n");
    }


    free(password);
    fclose(src);
    fclose(dest);
}