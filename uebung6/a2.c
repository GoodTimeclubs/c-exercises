#include <stdio.h>
#include <stdlib.h>

int main (){

	char zahlen[12];
	int i = 0;


	//Eingabe
	for (i = 0; i < 12; i++){

		printf("Bitte geben Sie die %d. Zahl ein:", i+1);

		scanf("%hhi", &zahlen[i]);

	}

	//Ausgabe
	
	for (i = 0; i < 12; i++){
	
		printf("Der %d. ASCII-Wert lautet %d und ist das Zeichen %c\n", i+1, zahlen[i], zahlen[i]);
	}


	printf("%s",zahlen);
	
	printf("\n");
}
