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
    struct Knote * anfang;

    anfang = &erster;

    struct Element ende;
    ende.zahl = -12;
    ende.next = NULL;

    struct Element vorletzter_knoten;
    vorletzter_knoten.zahl = 7;
    vorletzter_knoten.next = &ende;

    struct Element erster;
    erster.zahl = 42;
    erster.next = NULL;

    struct Element zweiter;
    zweiter.zahl = 10;
    erster.next = &zweiter;
    zweiter.next = &vorletzter_knoten;
}