#include <stdio.h>
double eingabeEinlesen(){ //Benutzereingabe
    double eingabe = 0.0;
    printf("Wie groß ist der Euro-Betrag, welcher in moeglichst wenig Muenzen aufgeteilt werden soll? ");
    scanf("%lf", &eingabe);
    return eingabe;
}

void numberToText(int anzahl){ //Zahlen ausgeben und 1 bis 5 in ausgeschriebene Zahlen umwandeln
    if (anzahl == 1)
    {
        printf("Eine");
    }
    if (anzahl == 2)
    {
        printf("Zwei");
    }
    if (anzahl == 3)
    {
        printf("Drei");
    }
    if (anzahl == 4)
    {
        printf("Vier");
    }
    if (anzahl == 5)
    {
        printf("Fuenf");
    }
    if (anzahl >= 6)
    {
        printf("%i", anzahl);
    }
    
}

void EuroMuenze(int muenze){ //Ausgabe von Euro Münzen
    printf(" x %i-Euro-Muenze\n", muenze/100);
}

void CentMuenze(int muenze){ //Ausgabe von Cent Münzen
    printf(" x %i-Cent-Muenze\n", muenze);
}

int anzahlBerechen(int* muenzen, double eingabe, int i){ //Anzahl für die aktuelle Münze aus dem Aray berechnen
    int muenzwert = muenzen[i];
    int anzahl = (int)eingabe / muenzwert;
    int rest = (int)eingabe % muenzwert;
    
    if(!(anzahl == 0)) //Nur Ausgabe, wenn mindestens eine Münze benötigt wird
    {
        numberToText(anzahl);

        if (muenzen[i] >= 100){
            EuroMuenze(muenzen[i]);
        }else{
            CentMuenze(muenzen[i]);
        }
    }
    return rest; //verbliebenen Betrag zurückgeben
}


int main (){
    int muenzen[8] = {200,100,50,20,10,5,2,1}; //Definition der zu verwendenden Münzen in Cent-Werten
    int i = 0;
    double rest = 0;
    rest = eingabeEinlesen()*100; // Eingabe mal 100 um eingegebenen Betrag ganzzahlig in cent zu berechnen
    
    for(i = 0; i<8; i++){ //Anzahl jeder münze durch Funktion berechnen und ausgeben
        rest = anzahlBerechen(muenzen, rest, i);
    }
    return 0;
}