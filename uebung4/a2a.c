#include <stdio.h>

int main (){

	double zahl1 = 0;
	double zahl2 = 0;

	double summe = 0;

	//Eingabe der Zahlen durch den Benutzer

	printf("\nGeben Sie eine Zahl ein: ");
	scanf("%lf", &zahl1);
	
	printf("\nGeben Sie noch eine Zahl ein: ");
	scanf("%lf", &zahl2);

	//Berechnung der Summe

	summe = zahl1 * zahl2;
	
	printf("\nDie Summe beider Zahlen ist ");

	if ((summe - (int)summe) == 0){

		printf("%d.\n", (int) summe);
	
	} else {
	
		printf("%f.\n", summe);
	
	}

}
