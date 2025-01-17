#include <stdio.h>
#include <stdlib.h>
//einfach verkettete Liste 
struct Knoten 
{
    int zahl;
    struct Knoten * next;
};

struct Knoten* einfügen(struct Knoten* anfang, int neue_zahl)
{
    struct Knoten* neu = malloc (sizeof(struct Knoten));
    neu -> zahl = neue_zahl;
    neu -> next = anfang;
    return neu;
}

void ausgabe (struct Knoten* liste)
{
    if (liste != NULL)
    {
        printf("%d\n", liste->zahl);
        ausgabe(liste->next);
    }
}

void delete(struct Knoten* liste)
{
    if (liste != NULL)
    {
        free(liste);
        delete(liste->next);
    }
}

void print_index (int index, struct Knoten* liste)
{
    int i = 0;
    while(i<=index && liste != NULL)
    {
        liste = liste->next;
        i++;
    }
    printf("%d\n", liste->zahl);
}
int main ()
{
    struct Knoten* anfang = NULL;
    anfang = einfügen(anfang, 1);
    anfang = einfügen(anfang, 2);
    anfang = einfügen(anfang, 3);
    anfang = einfügen(anfang, 4);
    anfang = einfügen(anfang, 5);
    print_index(1,anfang);
    delete(anfang);
}