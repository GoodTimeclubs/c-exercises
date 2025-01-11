#include <stdio.h>
int eingabeEinlesen(){
    double eingabe = 0.0;
    printf("Wie groß ist der Euro-Betrag, welcher in moeglichst wenig Muenzen aufgeteilt werden soll? ");
    scanf("%lf", &eingabe);
    return (int)(eingabe);
}


void numberToString(int anzahl){
    char eins[sizeof(char)*5] = {"E","i","n","e",'\0'};
    char zwei[sizeof(char)*5] = {"Z","w","e","i",'\0'};
    char drei[sizeof(char)*5] = {"D","r","e","i",'\0'};
    char vier[sizeof(char)*5] = {"V","i","e","r",'\0'};
    char fuenf[sizeof(char)*6] = {"F","u","e","n","f",'\0'};

    if(anzahl == 1)
    {
        printf("%s",eins);
    }
    if(anzahl == 2)
    {
        printf("%s",zwei);
    }
    if(anzahl == 3)
    {
        printf("%s",drei);
    }
    if(anzahl == 4)
    {
        printf("%s",vier);
    }
    if(anzahl == 5)
    {
        printf("%s",fuenf);
    }
}

void EuroMuenze(int anzahl, int muenze){
    if (anzahl)
    {
        numberToString(anzahl);
        printf(" x %i-Euro-Muenze\n", anzahl, muenze/100);
    }
}

void CentMuenze(int anzahl, int muenze){
    if (anzahl)
    {
        numberToString(anzahl);
        printf("x %i-Cent-Muenze\n", anzahl, muenze);
    }
}

int anzahlBerechen(int* muenzen, double eingabe, int i){
    int muenzwert = muenzen[i];
    int anzahl = (int)eingabe / muenzwert;
    int rest = (int)eingabe % muenzwert;

    if (muenzen[i] >= 100){
        EuroMuenze(anzahl, muenzen[i]);
    }else{
        CentMuenze(anzahl, muenzen[i]);
    }
    return rest;
}


int main (){
    int muenzen[8] = {200,100,50,20,10,5,2,1};
    int i = 0;
    double rest = 0;
    double eingabe = 0;
    eingabe = eingabeEinlesen()*100;
    rest = eingabe;
    
    for(i = 0; i<8; i++){
        rest = anzahlBerechen(muenzen, rest, i);
    }
}