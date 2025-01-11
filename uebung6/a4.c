#include<stdio.h>

int main () {

	char text[256];
	int i = 0;
	int laenge = 0;	

	printf("Bitte geben Sie etwas ein:");
	scanf("%s", text);

	while(text[laenge] != '\0')laenge++;

	for(i = 0; i < laenge; i++){
		
		printf("Das Zeichen am Index %d hat den ASCII-Wert %d.\n",i , text[i]);
	
	}



}
