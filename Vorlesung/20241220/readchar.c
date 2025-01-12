#include <stdio.h>
#include <stdlib.h>

char* readtext (){
    int puffergroeße = 10;
    char* puffer = malloc(puffergroeße);
    int eingabeposition = 0;
    char eingegebeneszeichen = 0;

    do{
        eingegebeneszeichen = getchar();  // ein Zeichen der Console einlesen
        if (eingegebeneszeichen != '\n'){
            puffer[eingabeposition] = eingegebeneszeichen;
            eingabeposition++;
            if (puffergroeße = eingabeposition){
                puffergroeße = puffergroeße +10;
                puffer = realloc(puffer, puffergroeße);
            }
        }
    }while(eingegebeneszeichen != '\n');

    puffer[eingabeposition] = '\0';

    puffer = realloc(puffer, eingabeposition+1);

    return puffer;
}



int main (){
    printf("Bitte gib einen Text ein: \n");
    char* eingabe = readtext();
    printf("%s\n", eingabe);
    
    free (eingabe);

    return 0;
}