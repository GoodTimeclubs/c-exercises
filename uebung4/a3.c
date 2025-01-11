#include <stdio.h>


int main (){

	double a = 0;
	double b = 0;
	double c = 0;

	int biggest = 0;
	int smallOne = 0;
	int smallTwo = 0;	

	printf("\nBitte geben Sie die Laenge der Seite a ein:");
	scanf("%le", &a);
	
	printf("\nBitte geben Sie die Laenge der Seite b ein:");
	scanf("%le", &b);

	printf("\nBitte geben Sie die Laenge der Seite c ein:");
	scanf("%le", &c);

	//Berechnung des Winkels und der Hypotenuse

	if(a > b && a > c){
		biggest = a;
		smallOne = b;
		smallTwo = c;
	}
	if(b > a && b > c){
		biggest = b;
		smallOne = c;
		smallTwo = a;
	}
	if(c > a && c > b){
		biggest = c;
		smallOne = b;
		smallTwo = a;
	}
	
	if (smallOne*smallOne + smallTwo*smallTwo == biggest*biggest){
		printf("\nDas Dreieck hat einen rechten Winkel und die Hypotenuse ist ");

		if (biggest == a){
			printf("a.\n");
		}	

		if (biggest == b){
			printf("b.\n");
		}

		if (biggest == c){
			printf("c.\n");
		}
	} else {
		printf("\nDas Dreieck hat keinen rechten Winkel.\n");
	}
}
