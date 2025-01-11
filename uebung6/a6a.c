#include <stdio.h>

int main () {

	char zahlen [200];
	int l = 0;
	int i = 0;

	printf("Bitte gebe eine Zahl ein: ");
	scanf("%s", zahlen);

	while(zahlen[l] != '\0') l++;
	
	printf("Umgedreht ist es: ");
	
	for (i = 0; i <= l; i++){

		printf("%c", zahlen[l-i]);
	
	}

	printf("\n");

}
