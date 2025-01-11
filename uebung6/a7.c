#include <stdio.h>

int main () {

	char zahlen [200];
	int l = 0;
	int i = 0;
	int zahl = 0;
	
	printf("Bitte gebe eine Zahl ein: ");
	scanf("%s", zahlen);

	while(zahlen[l] != '\0') l++;
	
		
	for (i = 0; i < l; i++){
		zahl = zahl + (int)zahlen[i] - 48;
		zahl = zahl * 10;
	}

	zahl = zahl /10;

	printf("Die Eingabe war: %i\n", zahl);

}
