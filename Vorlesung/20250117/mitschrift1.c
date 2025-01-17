#include <stdio.h>
#include <stdlib.h>
//einfach verkettete Liste
struct Knoten 
{
    int zahl;
    struct Knoten * next;
};

int main ()
{
    struct Knoten * anfang;
    struct Knoten * neu;

    neu = malloc(sizeof(struct Knoten));
    anfang = neu;

    neu ->zahl = 42;
    neu -> next = NULL;

    neu = malloc(sizeof(struct Knoten));
    neu -> zahl = 10;
    neu -> next = NULL;
    anfang -> next = neu;

    neu = malloc(sizeof(struct Knoten));
    neu -> zahl = 7;
    neu -> next = NULL;

    anfang ->next->next = neu;

    neu = malloc(sizeof(struct Knoten));
    neu -> zahl = -12;
    neu -> next = NULL;

    anfang ->next->next ->next = neu;
}