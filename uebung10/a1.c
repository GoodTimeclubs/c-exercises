#include <stdio.h>
#include <stdlib.h>
#include "../tools/readint.c"
#include "../tools/readtext.c"

struct Element 
{
    int inhalt;
    struct Element * nachfolger;
};

struct Element* insert_b(struct Element* anfang, int i)//fügt einen Knoten am Anfang der Liste ein
{
    struct Element* new = malloc(sizeof(struct Element));
    new->nachfolger = anfang;
    new->inhalt = i;

    return new;
}

int countKnoten(struct Element* anfang, int inhalt)//zählt zusammenhängende Knoten
{
    if (anfang->nachfolger != NULL)
    {
        inhalt = countKnoten(anfang->nachfolger, inhalt);
    }
    inhalt = inhalt +1;
    return inhalt;
}

void printList(struct Element* anfang, int size) //gibt zusammenhängende Knoten aus
{
    printf("Knoten nr. %d mit dem Inhalt %d\n",size - countKnoten(anfang, 0), anfang->inhalt);
    if (anfang->nachfolger != NULL)
    {   
        printList(anfang->nachfolger, size);
    }
    

}

struct Element* delKnoten(struct Element* anfang , int count) //löscht einen angegebenen Knoten
{
    int eingabe = 0;
    int i = 0;
    struct Element* todelete;
    struct Element* out;

    out = anfang;

    do
    {
        printf("Welcher Knoten soll gelöscht werden?\n");
        eingabe = readint();
    } while (eingabe > count);
    
    if(eingabe == 0) //wenn der erste Knoten betroffen ist
    {
        todelete = anfang;
            
        out = anfang->nachfolger;
            
            
    }else{

        for (i = 0; i<eingabe; i++)
        {
            
            if(eingabe-1 == i) //bei restlichen Knoten
            {
                todelete = anfang->nachfolger;
                anfang->nachfolger = anfang->nachfolger->nachfolger;
            }
            else if (anfang->nachfolger != NULL)
            {
            anfang = anfang->nachfolger;
            }
            ;
        }
    }
    free(todelete); //ToDo schlägt bei erstem Knoten fehl 
    return out;
}


struct Element* getKnoten(struct Element* anfang , int count, int eingabe) //gibt den knoten an der Stelle von Eingeben
{
    int i = 0;
    struct Element* out;
    
    for (i = 0; i<=eingabe; i++)
    {
        if(eingabe == 0) //wenn der erste Knoten betroffen ist
        {
            if (anfang->nachfolger != NULL)
            {
                out->nachfolger = anfang->nachfolger;
                out->inhalt = anfang->inhalt;
            }
            
        }
        else if((eingabe) == i) //bei restlichen Knoten
        {
            out->nachfolger = anfang->nachfolger;
            out->inhalt = anfang->inhalt;
        }
        else if (anfang->nachfolger != NULL)
        {
        anfang = anfang->nachfolger;
        }
    }
    return out;
}


int main ()
{
    //initialisierung
    struct Element* anfang = NULL;
    int choice = -1;
    anfang = insert_b(anfang, 1);
    anfang = insert_b(anfang, 2);
    anfang = insert_b(anfang, 3);
    anfang = insert_b(anfang, 4);
    anfang = insert_b(anfang, 5);

    while (choice != 0)
    {
        printf("\nWas möchten sie tun?\n\n");
        printf("1 - linked List ausgeben\n");
        printf("2 - Element am Anfang der Liste hinzufügen\n");
        printf("3 - Knoten aus Liste löschen\n");
        printf("4 - Inhalt eines Knotens ausgeben\n");
        printf("0 - Programm verlassen\n");
        choice = readint();

        if (choice == 0) return 0;
        if (choice == 1) printList(anfang, countKnoten(anfang, 0));
        if (choice == 2)
        {
            printf("Welcher ganzzahligen Inhalt soll der neue Knoten haben?");
            anfang = insert_b(anfang, readint());
        }
        if (choice == 3) anfang = delKnoten(anfang, countKnoten(anfang, 0));
        if (choice == 4) 
        {
            printf("Welcher Knoten soll ausgegeben werden?\n");
            struct Element* test = getKnoten(anfang, countKnoten(anfang, 0), readint());
            printf("Der Knoten hat den Inhalt %i und den Nachfolger %p\n", test->inhalt, test->nachfolger);
        }
    }
}