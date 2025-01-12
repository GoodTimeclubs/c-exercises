#include <stdio.h>
#define ANZAHL 10
int main(){

    int zahlen[ANZAHL]; //Array mit 3 intager Zahlen  start des Index bei 0 und Ende bei 2

    for(int i=0; i<ANZAHL; i++){
        printf("Bitte gib die %d. Zahl ein:",i+1);
        scanf("%d",&zahlen[i]);
    }

    for(int i=0; i<ANZAHL; i++){
        printf("Die %d. Zahl ist: %d\n",i+1, zahlen[i]);
    }
}