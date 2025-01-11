#include <stdio.h>


int main () {

	char eingabe [200];
	int slaenge = 0;	
	int i = 0;

	printf("Bitte geben Sie eine Zeichenkette ein: ");

	scanf("%s", eingabe);

	printf("Sie gaben \" %s \" ein.\n", eingabe);

	// Erkennen der Stringlänge
	while (eingabe[slaenge] != '\0') slaenge++;

	for (i = 0; i < slaenge; i++){

		if (eingabe[i] >= 97 && eingabe[i] <= 122 || eingabe[i] >= 65 && eingabe[i] <= 90){
		
			eingabe[i] = eingabe[i] + 1;		

		}
	
	}
	
	printf("1. Aenderung: \" %s \"\n", eingabe);

	for (i = 0; i < slaenge; i++){
		
		//kleiner Buchstabe
		if (eingabe[i] >= 97 && eingabe[i] <= 122){
		
			eingabe[i] = eingabe[i] - 32;		

		} else if (eingabe[i] >= 65 && eingabe[i] <= 90){ //großer Buchstabe
		
			eingabe[i] = eingabe[i] + 32;		

		}
	}
	

	printf("2. Aenderung: \" %s \"\n", eingabe);
	
	printf("Buchstaben: \""); 

	for (i = 0; i < slaenge; i++){

		if (eingabe[i] >= 97 && eingabe[i] <= 122 || eingabe[i] >= 65 && eingabe[i] <= 90){
		
			printf("%c", eingabe[i]);
					

		}
	
	}
	
	printf("\"\n"); 
}
