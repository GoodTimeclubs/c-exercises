#include <stdio.h>
#include <stdlib.h>
//einfach verkettete Liste vorne anfügen
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

void ausgabe (struct Knoten* iterator)
{
    while (iterator != NULL)
    {
        printf("%d\n", iterator->zahl);
        iterator = iterator->next;
    }
}
int main ()
{
    struct Knoten* anfang = NULL;
    anfang = einfügen(anfang, 1);
    anfang = einfügen(anfang, 2);
    anfang = einfügen(anfang, 3);
    anfang = einfügen(anfang, 4);
    anfang = einfügen(anfang, 5);
    ausgabe(anfang);
}