#include <stdio.h>

int main (){

	int zahl = 0; //initialisieren, damit die Eingabe immer als int richtig bearbeitet wird

	printf("Bitte geben Sie die Zahl an:");

	scanf("%d", &zahl); //scanf braucht die Speicheradresse, an der die Eingabe abgespeichert wird.
	
	printf("\nSoso, die Zahl lautet also %d\n", zahl);


} 
