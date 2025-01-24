#include <stdio.h>
#include <stdlib.h>
//einfach verkettete Liste
struct Element 
{
    int zahl;
    struct Element * next;
};

int main ()
{
    struct Element * anfang;
    struct Element * neu;

    neu = malloc(sizeof(struct Element));
    anfang = neu;

    neu ->zahl = 42;
    neu -> next = NULL;

    neu = malloc(sizeof(struct Element));
    neu -> zahl = 10;
    neu -> next = NULL;
    anfang -> next = neu;

    neu = malloc(sizeof(struct Element));
    neu -> zahl = 7;
    neu -> next = NULL;

    anfang ->next->next = neu;

    neu = malloc(sizeof(struct Element));
    neu -> zahl = -12;
    neu -> next = NULL;

    anfang ->next->next ->next = neu;
}