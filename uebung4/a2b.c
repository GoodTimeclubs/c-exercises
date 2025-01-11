#include <stdio.h>

int main (){

	double zahl1 = 0;
	double zahl2 = 0;

	double summe = 0;
	double nkomma = 0;
	
	int nkommaE = 0; 
	int nkommaZ = 0; 
	int nkommaD = 0; 
	int kommastellen = 0;
	//Eingabe der Zahlen durch den Benutzer

	printf("\nGeben Sie eine Zahl ein: ");
	scanf("%lf", &zahl1);
	
	printf("\nGeben Sie noch eine Zahl ein: ");
	scanf("%lf", &zahl2);

	//Berechnung der Summe

	summe = zahl1 + zahl2;
	
	printf("\nDie Summe beider Zahlen ist ");


	//berechnung der Nachkommastellen	

	nkomma = (summe - ((int)summe));

	nkommaE = nkomma*10;
	
	nkommaZ = (nkomma*10-nkommaE)*10;

	nkommaD = ((nkomma*100-nkommaZ)-nkommaE*10)*10;


	if (nkommaE) {
		kommastellen = 1;

		if (nkommaZ){
			kommastellen = 2;

			if (nkommaD){
				kommastellen = 3;
			}
		}
	}

	if(kommastellen == 0){
	
		printf("%d\n", (int)summe);
	
	}

	if(kommastellen == 1){

		printf("%.1lf\n", summe);
	
	}
	if(kommastellen == 2){
	
		printf("%.2lf\n", summe);	
	
	}
	if(kommastellen == 3){
	
		printf("%.3lf\n", summe);
	
	}
	

}
