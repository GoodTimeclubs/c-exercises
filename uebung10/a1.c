#include <stdio.h>
#include <stdlib.h>
#include "../tools/readint.c"
#include "../tools/readtext.c"

struct Knoten 
{
    int inhalt;
    struct Knoten * nachfolger;
};

struct Knoten* insert_b(struct Knoten* anfang, int i)
{
    struct Knoten* new = malloc(sizeof(struct Knoten));
    new->nachfolger = anfang;
    new->inhalt = i;

    return new;
}

void printKnoten(struct Knoten* anfang)
{
    if (anfang->nachfolger != NULL)
    {
        printKnoten(anfang->nachfolger);
    }
    printf("%d\n", anfang->inhalt);
}

int countKnoten(struct Knoten* anfang, int count)
{
    if (anfang->nachfolger != NULL)
    {
        count = countKnoten(anfang->nachfolger, count);
    }
    count = count +1;
    return count;
}

void delKnoten(struct Knoten* anfang , int count)
{
    int eingabe = 0;
    do
    {
        printf("Welcher Knoten soll gelöscht werden?\n");
        eingabe = readint();
    } while (eingabe > count);
    
    int i = 0;
    
    for (i = 0; i<count; i++)
    {
        anfang = anfang->nachfolger;
    }
    printf("Knoten NR. %d gefunden.", anfang.inhalt);
    
}

int main ()
{
    struct Knoten* anfang = NULL;
    anfang = insert_b(anfang, 1);
    anfang = insert_b(anfang, 2);
    anfang = insert_b(anfang, 3);
    anfang = insert_b(anfang, 4);
    anfang = insert_b(anfang, 5);

    printKnoten(anfang);
    delKnoten(anfang, countKnoten(anfang, 0));

}