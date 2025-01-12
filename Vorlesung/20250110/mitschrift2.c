#include <stdio.h>
#include <stdlib.h>

struct Person {
    char vorname[20];
    char nachname[20];
    unsigned int alter;
}; //Hier Semikolon

struct Person2 {
    char* vorname;
    char* nachname;
    unsigned int alter;
}; //Hier Semikolon




int main (){
    struct Person test;

    test.vorname = "Max";
    test.nachname = "Musterman";
    test.alter = 30;

    struct Person einwohner[1000000];

    printf("%s\n", einwohner[99].vorname);

    struct Person2 villager;

    villager.vorname = malloc(20);

    villager.vorname = "Bernd";

    villager.nachname = malloc(20);

    villager.nachname = NULL;

    villager.alter = 2;

    printf("Vorname: %s", villager.vorname);

    free(villager.vorname);

    return 0;
}