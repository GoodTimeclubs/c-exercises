#include <stdio.h>

int main (){

	double eingabe = 1;
	double summe = 0;
	double minEingabe = 0;
	double maxEingabe = 0;

	while (eingabe != 0){

		printf("Bitte gebe eine Zahl ein (0 fuer Abbruch):");
		scanf("%le", &eingabe);

		summe = summe + eingabe;

		if (minEingabe > eingabe || minEingabe == 0){
		
			minEingabe = eingabe;
		}

		if (maxEingabe < eingabe || maxEingabe == 0){

			maxEingabe = eingabe;

		}
	}
	printf("Die Summe lautet %lf\n", summe);
	printf("Das Maximum ist %lf\n", maxEingabe);
	printf("Das Minimum ist %lf\n", minEingabe);

	return 0;
}
