#include <stdio.h>
#include <stdlib.h>

int eingabe(int* zahlen){ // Einlesen der Zahl vom Benutzer
	int i = 2;
	int choice = 0;
	do{
		
		i++;
		printf("%i\n",i);
		zahlen = realloc(zahlen,i * sizeof(int));

		printf("Bitte geben sie eine ganze Zahl ein: ");
		scanf("%i", &zahlen[i]);
		// Abfragen ob eine weitere Zahl eingegeben werden soll
		
		printf("Soll eine weitere Zahl eingegeben werden? ( 1 = Ja / 2 = Nein) ");
		scanf("%i", &choice);

	}while (choice == 1);
	return i;
}

int min(int* zahlen, int numbercount){	// Berechnen der minimalen Zahl
	int i = 0;
	int min = 0;
	
	for (i = 0; i < numbercount; i++){
		if (zahlen[i] < min || min == 0){
			min = zahlen[i];
		}	
	}
	return min;
}

int max(int* zahlen, int numbercount){ // Berechnen der maximalen Zahl
	int i = 0;
	int max = 0;
	
	for (i = 0; i < numbercount; i++){
		if (zahlen[i] > max || min == 0){
			max = zahlen[i];
		}	
	}
	return max;
}

double avg(int* zahlen, int numbercount){ // Berechnen des Durchschnitts
	int i = 0;
	double avg = 0;
	
	for (i = 0; i < numbercount; i++){
		avg = avg + zahlen[i];
	}
	avg = avg / 10;
	return avg;
}

void ausgabe(int min, int max, double avg){ // Ausgabe der Werte an den Benutzer

	printf("Die kleinste Zahl ist: %i\n", min);
	printf("Die groesste Zahl ist: %i\n", max);
	printf("Der Durchschnitt ist: %.2lf\n", avg);
}

int main (){
	int numbercount = 0;
	int* zahlen = malloc(2);
	int i = 0;
	int klein;
	int gross;
	double schnitt;

	// Einlesen der Zahlen
	numbercount = eingabe(zahlen);

	// Berechnungen
	klein = min(zahlen, numbercount);
	gross = max(zahlen, numbercount);
	schnitt = avg(zahlen, numbercount); 
	// Ausgabe an Benutzer	
	ausgabe(klein,gross,schnitt);

	free(zahlen);
	return 0;
}
