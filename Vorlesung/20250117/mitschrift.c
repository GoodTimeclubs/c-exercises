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
    struct Knote * anfang;

    anfang = &erster;

    struct Knoten ende;
    ende.zahl = -12;
    ende.next = NULL;

    struct Knoten vorletzter_knoten;
    vorletzter_knoten.zahl = 7;
    vorletzter_knoten.next = &ende;

    struct Knoten erster;
    erster.zahl = 42;
    erster.next = NULL;

    struct Knoten zweiter;
    zweiter.zahl = 10;
    erster.next = &zweiter;
    zweiter.next = &vorletzter_knoten;
}