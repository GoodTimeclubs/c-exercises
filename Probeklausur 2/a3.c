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

struct Element* join(struct Element* erste, struct Element* zweite){
    
    struct Element* temp;

    while (erste != NULL){
        insert_b (temp,erste->inhalt);
            erste = erste->nachfolger;
    }

    while (zweite != NULL){
        insert_b (temp,zweite->inhalt);
        zweite = zweite->nachfolger;
    }

    return temp;
}

void printList(struct Element* anfang) //gibt zusammenhängende Knoten aus
{
    printf("Knoten mit dem Inhalt %d\n", anfang->inhalt);
    if (anfang->nachfolger != NULL)
    {   
        printList(anfang->nachfolger);
    }
    

}


int main ()
{
    //initialisierung
    struct Element* erste = NULL;
    struct Element* zweite = NULL;

    erste = insert_b(erste, 1);
    erste = insert_b(erste, 2);
    erste = insert_b(erste, 3);
    erste = insert_b(erste, 4);
    erste = insert_b(erste, 5);

    zweite = insert_b(zweite, 6);
    zweite = insert_b(zweite, 7);
    zweite = insert_b(zweite, 8);
    zweite = insert_b(zweite, 9);
    zweite = insert_b(zweite, 10);
    
    struct Element* ausgabe = join(erste, zweite);

    printList(ausgabe);
}