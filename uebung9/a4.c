#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"
#include "readint.c"

struct Person
{
    char* Vorname;
    char* Nachname;
    int Alter;
    int Geschlecht;
};

struct Person getPerson()
{
    struct Person Input;

    Input.Vorname = malloc(sizeof(char)*20);
    Input.Nachname = malloc(sizeof(char)*20);
    Input.Vorname[0] = '\0';
    Input.Nachname[0] = '\0';
    Input.Alter = 0;
    Input.Geschlecht = 0;
    
    printf("Bitte geben Sie den Vornamen ein:\n");
    Input.Vorname = readtext();
    printf("Bitte geben Sie den Nachnamen von %s ein:\n", Input.Vorname);
    Input.Nachname = readtext();
    
    do
    {
        printf("Bitte geben Sie das Geschlecht von %s %s ein [1 Männlich | 2 Weiblich]:\n", Input.Vorname, Input.Nachname);
        Input.Geschlecht = readint();
    } while (Input.Geschlecht == 0 || Input.Geschlecht >= 3);
    
    
    printf("Bitte geben Sie das Alter von %s %s ein:\n", Input.Vorname, Input.Nachname);
    Input.Alter = readint();
    
    return Input;
}

void printPerson(struct Person Input){
    if (Input.Geschlecht == 1) printf("Herr ");
    if (Input.Geschlecht == 2) printf("Frau ");

    printf("%s %s (%d)\n", Input.Vorname, Input.Nachname, Input.Alter);
}

void newPerson(struct Person* Adressbuch, int size){
    int i = 0;
    for(i=0;i<size; i++)
    {
        if(&Adressbuch[i].Vorname == '\0');
    }
}

int main (){
    unsigned int adressbuchSize = 1;
    struct Person* Adressbuch = malloc(adressbuchSize);
    
    newPerson(Adressbuch, adressbuchSize);
    
}