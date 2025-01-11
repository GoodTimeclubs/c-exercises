#include <stdio.h>

int main () {

	//Programmstart
	printf("Bitte einen Moment warten. Ich rechne...\n");

	//deklarierung der Variablen
	int x = 10;
	int y = 20;
	int z = 30;

	printf("Summe: %i\n", (10+20+30));
	
	int berechnung1 = (x*y/z);

	printf("Berechnung 1: %i\n", berechnung1);

	int rest_berechnung1 = (x*y%z);
	
	printf("Der return-Wert kann mit \"echo $?\" ausgelesen werden.\n");

	return rest_berechnung1;
}
