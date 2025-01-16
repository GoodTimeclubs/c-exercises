#include <stdio.h>
#include <stdlib.h>
#include "readtext.c"
#include "readint.c"

struct Person
{
    char *Vorname;
    char *Nachname;
    int Alter;
    int Geschlecht;
};

void getPerson(struct Person *Input, int i)
{
    printf("Bitte geben Sie den Vornamen ein:\n");
    Input[i].Vorname = readtext();
    printf("Bitte geben Sie den Nachnamen von %s ein:\n", Input[i].Vorname);
    Input[i].Nachname = readtext();
    printf("Bitte geben Sie das Geschlecht von %s %s ein [1 Männlich | 2 Weiblich]:\n", Input[i].Vorname, Input[i].Nachname);
    Input[i].Geschlecht = readint();
    printf("Bitte geben Sie das Alter von %s %s ein:\n", Input[i].Vorname, Input[i].Nachname);
    Input[i].Alter = readint();
    printf("Eingelesens Alter : %d\n", Input[i].Alter);
}

void printPerson(struct Person Input)
{
    if (Input.Geschlecht == 0)
        printf("[Kein Geschlecht angegeben]");
    else
    {
        if (Input.Geschlecht == 1)
            printf("Herr ");
        if (Input.Geschlecht == 2)
            printf("Frau ");
    }
    if (Input.Vorname == NULL)
    {
        printf("[Kein Vorname angegeben]");
    }
    else if (Input.Vorname[0] = '\0')
    {
        printf("[Kein Vorname angegeben]");
    }
    else
    {
        printf("%s ", Input.Vorname);
    }
    if (Input.Nachname == NULL)
    {
        printf("[Kein Nachname angegeben]");
    }
    else if (Input.Nachname[0] = '\0')
    {
        printf("[Kein Vorname angegeben]");
    }
    else
    {
        printf("%s ", Input.Nachname);
    }
    if (Input.Alter == 0)
    {
        printf("[Kein Alter angegeben]");
    }
    else
    {
        printf("(%d) ", Input.Alter);
    }

    printf("\n");
}

void newPerson(struct Person *Adressbuch, int *size)
{
    int i = 1;
    int i2 = 0;
    int freeSpot = -1;
    while (freeSpot == -1)
    {

        if (Adressbuch[i].Vorname == NULL && Adressbuch[i].Nachname == NULL)
        {
            freeSpot = i;
        }
        i++;
    }

    getPerson(Adressbuch, freeSpot);
    printPerson(Adressbuch[freeSpot]);
}

int searchPerson(struct Person *Adressbuch, int *size)
{
    printf("An welchem Speicherplatz ist die gewünschte Person gespeichert?\n");
    int result = readint();
    return result;
}

void delPerson(struct Person *Adressbuch, int *size)
{
    int i = -1;
    printf("Welcher Speicherplatz soll freigegeben werden?\n");
    i = readint();

    free(Adressbuch[i].Vorname);
    free(Adressbuch[i].Nachname);
    Adressbuch[i].Vorname = NULL;
    Adressbuch[i].Nachname = NULL;
    Adressbuch[i].Alter = 0;
    Adressbuch[i].Geschlecht = 0;

    printf("Die Person an dem %d. Speicherplatz wurde gelöscht.\n", i);
}

void printTable(struct Person *Adressbuch, int size)
{
    int i = 1;

    printf("Das Adressbuch hat aktuell die folgenden Einträge:\n");
    for (i = 0; i < size; i++)
    {
        if (Adressbuch[i].Vorname != NULL && Adressbuch[i].Nachname != NULL)
        {
            printf("%d : ", i);
            printPerson(Adressbuch[i]);

        }
    }
}

void compAge(struct Person *Adressbuch, int *size)
{
    printf("An welchem Speicherplatz ist die 1. Person?");
    int person1 = readint();

    printf("An welchem Speicherplatz ist die 2. Person?");
    int person2 = readint();

    if (Adressbuch[person1].Alter > Adressbuch[person2].Alter)
    {
        printf("%s %s ist mit einem Alter von %d %d Jahre aelter als %s %s mit dem Alter %d\n", Adressbuch[person1].Vorname, Adressbuch[person1].Nachname, Adressbuch[person1].Alter, Adressbuch[person1].Alter - Adressbuch[person2].Alter, Adressbuch[person2].Vorname, Adressbuch[person2].Nachname, Adressbuch[person2].Alter);
    }

    if (Adressbuch[person1].Alter < Adressbuch[person2].Alter)
    {
        printf("%s %s ist mit einem Alter von %d %d Jahre juenger als %s %s mit dem Alter %d\n", Adressbuch[person1].Vorname, Adressbuch[person1].Nachname, Adressbuch[person1].Alter, Adressbuch[person2].Alter - Adressbuch[person1].Alter, Adressbuch[person2].Vorname, Adressbuch[person2].Nachname, Adressbuch[person2].Alter);
    }
    if (Adressbuch[person1].Alter == Adressbuch[person2].Alter)
    {
        printf("Die Personen haben das gleiche Alter.\n");
    }
}

int main()
{
    int adressbuchSize = 100;
    int choice = 0;
    struct Person *Adressbuch = malloc(sizeof(struct Person) * adressbuchSize);

    do
    {
        printf("\nWillkommen im temporaeren Adressbuch!\n\n");
        printf("Bitte treffen sie eine Auswahl\n");
        printf("[1] Neue Person Anlegen\n");
        printf("[2] Person Anzeigen\n");
        printf("[3] Person löschen\n"); // ToDo Testen
        printf("[4] Alter von Personen vergleichen\n");
        printf("[5] Adressbuch ausgeben\n");
        printf("[0] Program verlassen\n");

        choice = readint();

        if (choice == 1)
            newPerson(Adressbuch, &adressbuchSize);
        if (choice == 2)
            printPerson(Adressbuch[searchPerson(Adressbuch, &adressbuchSize)]);
        if (choice == 3)
            delPerson(Adressbuch, &adressbuchSize);
        if (choice == 4)
            compAge(Adressbuch, &adressbuchSize);
        if (choice == 5)
            printTable(Adressbuch, adressbuchSize);
    } while (choice != 0);
}