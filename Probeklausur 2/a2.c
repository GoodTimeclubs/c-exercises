#include <stdio.h>
#include <stdlib.h>
#include "../tools/readtext.c"


char* trim (char* text){
    int erstesZeichen = 0;
    int letztesZeichen = 0;
    char* ausgabe;
    int i = 0;
    int laenge = 0;
    
    while(text[i] != '\0'){
        if (text[i] > ' '){
            laenge++;
        }
        i++;
    }
    ausgabe = malloc(sizeof(char)*laenge+1);
    
    while(text[i] != '\0'&& text[i] <= ' '){
        letztesZeichen = i;
        i--;
    }

    i = 0;
    while(text[i] != '\0'&& text[i] <= ' '){
        erstesZeichen = i;
        i++;
    }
    
    for(i = 0; i<=laenge; i++){
        ausgabe[i] = text[erstesZeichen+1+i];
    }
    ausgabe[i+1] = '\0';
    return ausgabe;
}
int main(){
    printf("Eingabe:");
    char* text = readtext();
    printf("Sie gaben \"%s\" ein.\n", text);
    char* ausgabe = trim(text);
    printf("Getrimmt: \"%s\"\n",ausgabe);
}