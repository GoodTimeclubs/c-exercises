#include <stdio.h>


int main () {

	double betrag = 0;

	int rest = 0;

	//Betrag einlesen
	printf("Bitte geben sie den umzuwnadelnden Betrag ein:");
	scanf("%lf", &betrag);

	//Umrechnung in Euro
	rest = betrag*100;
	//Evaluieren der Münzanzahlen
	if (rest >= 200){
	
		printf("%d x 2-Euro-Muenze\n", (int) betrag/200);
		rest = (int)betrag%200;
	}
	if (rest >= 100){
	
		printf("%d x 1-Euro-Muenze\n",  rest/100);
		rest = rest%100;
	}

	if (rest >= 50){
	
		printf("%d x 50-Cent-Muenze\n",  rest/50);
		rest = rest%50;
	}
	if (rest >= 20){
	
		printf("%d x 20-Cent-Muenze\n",  rest/20);
		rest = rest%20;
	}
	if (rest >= 10){
	
		printf("%d x 10-Cent-Muenze\n",  rest/10);
		rest = rest%10;
	}
	if (rest >= 5){
	
		printf("%d x 5-Cent-Muenze\n",  rest/5);
		rest = rest%5;
	}
	if (rest >= 2){
	
		printf("%d x 2-Cent-Muenze\n",  rest/2);
		rest = rest%2;
	}
	if (rest >= 1){
	
		printf("%d x 1-Cent-Muenze\n",  rest/1);
		rest = rest%1;
	}

}
