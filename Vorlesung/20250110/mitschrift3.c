#include <stdio.h>
#include <stdlib.h>

struct Person {
    char vorname[20];
    char nachname[20];
    unsigned int alter;
}; //Hier Semikolon

struct Person2 {
    char* vorname;
    char* nachname;
    unsigned int alter;
}; //Hier Semikolon

void freePerson(struct Person2* p){
    free(p -> vorname);
    p -> vorname = NULL;
    free(p -> nachname);
    p -> nachname = NULL;

    p -> alter = 0;
}

void einlesen(struct person2* pp){
    printf("Vorname:\n");
    pp -> vorname = readtext();// -> , da pp eine Adresse ist
    printf("Nachname:\n");
    pp -> nachname = readtext();
    printf("Alter:\n");
    scanf("%d", &pp -> alter);
}

int main (){
    int anzahl = 120;
    
    struct Person2* personen;

    personen = malloc(anzahl*sizeof(struct Person2));

    personen[0].alter++;

    einlesen (&personen[99]);

    free(personen);

    return 0;
}