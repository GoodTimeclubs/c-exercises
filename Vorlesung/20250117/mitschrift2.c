#include <stdio.h>
#include <stdlib.h>
//einfach verkettete Liste vorne anfügen
struct Element 
{
    int zahl;
    struct Element * next;
};

struct Element* einfügen(struct Element* anfang, int neue_zahl)
{
    struct Element* neu = malloc (sizeof(struct Element));
    neu -> zahl = neue_zahl;
    neu -> next = anfang;
    return neu;
}

void ausgabe (struct Element* iterator)
{
    while (iterator != NULL)
    {
        printf("%d\n", iterator->zahl);
        iterator = iterator->next;
    }
}
int main ()
{
    struct Element* anfang = NULL;
    anfang = einfügen(anfang, 1);
    anfang = einfügen(anfang, 2);
    anfang = einfügen(anfang, 3);
    anfang = einfügen(anfang, 4);
    anfang = einfügen(anfang, 5);
    ausgabe(anfang);
}