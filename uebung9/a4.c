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
    printf("Bitte geben Sie den Vornamen ein:\n");
    Input[i].Vorname = readtext();
    printf("Bitte geben Sie den Nachnamen von %s ein:\n", Input[i].Vorname);
    Input[i].Nachname = readtext();
    printf("Bitte geben Sie das Geschlecht von %s %s ein [1 Männlich | 2 Weiblich]:\n", Input[i].Vorname, Input[i].Nachname);
    Input[i].Geschlecht = readint();
    printf("Bitte geben Sie das Alter von %s %s ein:\n", Input[i].Vorname, Input[i].Nachname);
    Input[i].Alter = readint();
}

void printPerson(struct Person Input){
    if (Input.Geschlecht == 0) printf("[Kein Geschlecht angegeben]");
    else 
    {
        if (Input.Geschlecht == 1) printf("Herr ");
        if (Input.Geschlecht == 2) printf("Frau ");
    }
    if (Input.Vorname[0] == '\0') printf("[Kein Vorname angegeben]");
    else printf("%s ", Input.Vorname);
    if (Input.Nachname[0] == '\0') printf("[Kein Nachname angegeben]");
    else printf("%s ", Input.Nachname);
    if (Input.Alter == 0) printf("[Kein Alter angegeben]");
    else printf("(%d) ", Input.Alter);
    

    printf("\n");
}

void newPerson(struct Person* Adressbuch, int* size){
    int i = 0;
    int i2 = 0;
    int freeSpot = -1;
    while(freeSpot == -1)
    {
        if(i == *size)
        {
            *size = *size + 10;
            Adressbuch = realloc(Adressbuch, *size*sizeof(struct Person));
            
            for(i2=0;i<10;i++)
            {
            Adressbuch[i+i2].Vorname[0] = '\0';
            Adressbuch[i+i2].Nachname[0] = '\0';
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

int searchPerson(struct Person* Adressbuch, int* size)
{
    printf("Bitte geben sie den Vornamen der gesuchten Person ein:\n");
    char* vorname = readtext();
    printf("Bitte geben sie den Vornamen der gesuchten Person ein:\n");
    char* nachname = readtext();
    int result = -1;
    int i = 0;
    for(i=0;i<*size;i++)
    {
        if(Adressbuch[i].Vorname == vorname && Adressbuch[i].Nachname == nachname) result = i;
    }
    free(vorname);
    free(nachname);
    return result;
}

void delPerson(struct Person* Adressbuch, int* size)
{
    int i = -1;
    printf("Welche Person soll gelöscht werden?\n\n");
    i = searchPerson(Adressbuch, size);

    free(Adressbuch[i].Vorname);
    free(Adressbuch[i].Nachname);
    Adressbuch[i].Alter = 0;
    Adressbuch[i].Geschlecht = 0;

    printf("Die Person an dem %d. Speicherplatz wurde gelöscht.\n",i);
}



int main (){
    int adressbuchSize = 1;
    int choice = 0;
    struct Person* Adressbuch = malloc(sizeof(struct Person)*adressbuchSize);
    
    do
    {
    printf("\nWillkommen im temporaeren Adressbuch!\n\n");
    printf("Bitte treffen sie eine Auswahl\n");
    printf("[1] Neue Person Anlegen\n");
    printf("[2] Person Suchen\n");
    printf("[3] Person löschen\n");
    printf("[0] Program verlassen\n");

    choice = readint();

    if (choice == 1) newPerson(Adressbuch, &adressbuchSize);
    if (choice == 2) printPerson(Adressbuch[searchPerson(Adressbuch, &adressbuchSize)]);
    if (choice == 3) delPerson(Adressbuch, &adressbuchSize);
    } while (choice != 0);
    
}