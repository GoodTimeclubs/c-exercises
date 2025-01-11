#include <stdio.h>
#include <stdlib.h>

int main () {
	
	char z1[100];
	
	char* z2;
	int l = 0;
	int i = 0;

	printf("Bitte geben sie eine Zeichenkette ein: ");
	scanf("%s", z1);

	while(z1[l] != '\0') l++ ;

	z2 = malloc(l);

	for(i = 0; i<l; i++){

		z2[i] = z1[i];
	
	}
	printf("Die Zeichenkette am neuen Speicherort ist: %s\n", z2);
	free(z2);
}
