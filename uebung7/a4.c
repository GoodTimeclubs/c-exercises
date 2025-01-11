#include <stdio.h>
double eingabeEinlesen(){
    double eingabe = 0.0;
    printf("Wie groß ist der Euro-Betrag, welcher in moeglichst wenig Muenzen aufgeteilt werden soll? ");
    scanf("%lf", &eingabe);
    return eingabe;
}


void EuroMuenze(int anzahl, int muenze){
        printf("%i x %i-Euro-Muenze\n", anzahl, muenze/100);
}

void CentMuenze(int anzahl, int muenze){
        printf("%i x %i-Cent-Muenze\n", anzahl, muenze);
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