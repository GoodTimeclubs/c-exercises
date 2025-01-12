#include <stdio.h>

#define ALTER 12 //konstante, immer, wenn "ALTER" im quelltext gefunden wird wird es durch 12 ersetzt.

int main() {
	
	int zahl = 3; //Speicherplatz wird reserviert
	long alter_zahl;

	double eingabe1; //am Anfang der Variable darf keine Zahl stehen
			//double ist nicht immer genau!

	printf("%lu\n", sizeof(double));

	//Pointer
	int* p_zahl = &zahl; //durch das & vor der Variable wird die Speicheradresse der Variable abgerufen.
	printf("\n");
	printf("\n");
	printf("Inhalt der Variable \t\t= %d\n", zahl);
	printf("Speicheradresse der Variable \t= %p \t= %p\n", &zahl, p_zahl);
	printf("Inhalt an %p \t= %i\n", p_zahl, *p_zahl); //* zum abrufen des Inhalts der Adresse
	printf("\n");
	printf("\n");
	
	return 0;
}
