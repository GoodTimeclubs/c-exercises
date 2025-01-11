#include <stdio.h>

void eingabe(int* zahlen){ // Einlesen der Zahl vom Benutzer
	int i = 0;
	for (i=0; i<10; i++){
		printf("Bitte geben sie eine ganze Zahl ein: ");
		scanf("%i", &zahlen[i]);
	}
}

int min(int* zahlen){	// Berechnen der minimalen Zahl
	int i = 0;
	int min = 0;
	
	for (i = 0; i < 10; i++){
		if (zahlen[i] < min || min == 0){
			min = zahlen[i];
		}	
	}
	return min;
}

int max(int* zahlen){ // Berechnen der maximalen Zahl
	int i = 0;
	int max = 0;
	
	for (i = 0; i < 10; i++){
		if (zahlen[i] > max || min == 0){
			max = zahlen[i];
		}	
	}
	return max;
}

double avg(int* zahlen){ // Berechnen des Durchschnitts
	int i = 0;
	double avg = 0;
	
	for (i = 0; i < 10; i++){
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
	int zahlen[10];
	int i = 0;
	int klein;
	int gross;
	double schnitt;

	// Einlesen der Zahlen
	eingabe(zahlen);

	// Berechnungen
	klein = min(zahlen);
	gross = max(zahlen);
	schnitt = avg(zahlen); 
	// Ausgabe an Benutzer	
	ausgabe(klein,gross,schnitt);

	return 0;
}
