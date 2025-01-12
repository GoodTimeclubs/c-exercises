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

void getPerson(struct Person* Input, int i)
{
    Input[i].Vorname = malloc(sizeof(char)*20);
    Input[i].Nachname = malloc(sizeof(char)*20);
    Input[i].Vorname = 0;
    Input[i].Nachname = 0;
    
    printf("Bitte geben Sie den Vornamen ein:\n");
    Input[i].Vorname = readtext();
    printf("Bitte geben Sie den Nachnamen von %s ein:\n", Input[i].Vorname);
    Input[i].Nachname = readtext();
    
    do
    {
        printf("Bitte geben Sie das Geschlecht von %s %s ein [1 Männlich | 2 Weiblich]:\n", Input[i].Vorname, Input[i].Nachname);
        Input[i].Geschlecht = readint();
    } while (Input[i].Geschlecht == 0 || Input[i].Geschlecht >= 3);
    
    
    printf("Bitte geben Sie das Alter von %s %s ein:\n", Input[i].Vorname, Input[i].Nachname);
    Input[i].Alter = readint();
}

void printPerson(struct Person Input){
    if (Input.Geschlecht == 1) printf("Herr ");
    if (Input.Geschlecht == 2) printf("Frau ");

    printf("%s %s (%d)\n", Input.Vorname, Input.Nachname, Input.Alter);
}

void newPerson(struct Person* Adressbuch, int size){
    int i = 0;
    int i2 = 0;
    int freeSpot = -1;
    while(freeSpot == -1)
    {
        if(i == size)
        {
            size = size + 10;
            Adressbuch = realloc(Adressbuch, size*sizeof(struct Person));
            
            for(i2=0;i<10;i++)
            {
            Adressbuch[i+i2].Vorname = 0;
            Adressbuch[i+i2].Nachname = 0;
            Adressbuch[i+i2].Alter = 0;
            Adressbuch[i+i2].Geschlecht = 0;
            }
        }

        if(Adressbuch[i].Vorname == 0 && Adressbuch[i].Nachname == 0)
        {
            freeSpot = i;
        }
    }

    getPerson(Adressbuch,freeSpot);
    printPerson(Adressbuch[freeSpot]);


}

int main (){
    int adressbuchSize = 1;
    struct Person* Adressbuch = malloc(sizeof(struct Person)*adressbuchSize);
    
    newPerson(Adressbuch, adressbuchSize);
    
}