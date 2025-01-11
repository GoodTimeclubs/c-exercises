#include <stdio.h>

#define ANZAHL 10

int main (){
	//deklaration der Variablen
	int eingabe [ANZAHL];
	int summe = 0;
	int minEingabe = 0;
	int maxEingabe = 0;
	int zaehler = 0;
	double durchschnitt = 0;

	printf("Bitte geben Sie %d ganze Zahlen ein.\n", ANZAHL);
	//Einlesen von ANZAHL Zahlen
	for (zaehler = 0; zaehler < ANZAHL; zaehler ++){
		printf("%d. Zahl: ", zaehler+1);
		scanf("%d", &eingabe[zaehler]);
	}
	//Berechnung
	for (zaehler = 0; zaehler < ANZAHL; zaehler ++){
		if (minEingabe > eingabe[zaehler] || minEingabe == 0) minEingabe = eingabe[zaehler];
		if (maxEingabe < eingabe[zaehler] || maxEingabe == 0) maxEingabe = eingabe[zaehler]; 

		summe = eingabe[zaehler] + summe; 		
	}
	//Ausgabe
	for (zaehler = 0; zaehler < ANZAHL; zaehler ++){

		printf("\nDie %d. Zahl war %d", zaehler+1, eingabe[zaehler]);
		
		if (eingabe[zaehler] == minEingabe) printf(" <-- kleinste Zahl");
		if (eingabe[zaehler] == maxEingabe) printf(" <-- groeßte Zahl");
	}
	
	durchschnitt = (double)summe / ANZAHL;
		
	printf("\nDie Summe lautet %d\n", summe);
	printf("Der Durchschnitt lautet %.1lf\n", durchschnitt);

	return 0;
}
