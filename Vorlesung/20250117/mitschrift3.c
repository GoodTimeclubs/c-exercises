#include <stdio.h>
#include <stdlib.h>
//einfach verkettete Liste 
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

void ausgabe (struct Element* liste)
{
    if (liste != NULL)
    {
        printf("%d\n", liste->zahl);
        ausgabe(liste->next);
    }
}

void delete(struct Element* liste)
{
    if (liste != NULL)
    {
        free(liste);
        delete(liste->next);
    }
}

void print_index (int index, struct Element* liste)
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
    struct Element* anfang = NULL;
    anfang = einfügen(anfang, 1);
    anfang = einfügen(anfang, 2);
    anfang = einfügen(anfang, 3);
    anfang = einfügen(anfang, 4);
    anfang = einfügen(anfang, 5);
    print_index(1,anfang);
    delete(anfang);
}