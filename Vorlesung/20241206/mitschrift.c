#include <stdio.h>
#include <stdlib.h> // Standart Libary
int main (){

	// ASCII Codierung	
	//char zahlen [10] = {'H', 'A', 'L', 'L', 'O', '\0'}; // \0 um den String zu beenden 
	
	//char text [100] //Feste Speicherzuweisung beim Compilen
	


	//Dynamische Speicherzuweisung
	char* text = malloc(100); // wird erst zur Laufzeit definiert und nicht beim Compilen mit 100 Bytes

	int i;

	/*
	for (i=0; i<10; i++){
	
		//printf("zahlen[%d] = %d  = %c\n", i, zahlen[i], zahlen[i]);
		printf("%c",zahlen[i]);

	
	}
	printf("\n");
	
	printf("%s\n", zahlen);
	printf("%s\n", text);
	*/
	printf("Eingabe");
	scanf("%s", text);
	

	//Länge der Eingabe erkennen
	while(text[i] != '\0'){
		i++;
	}
	printf("Die Länge der Eingabe ist %d\n", i);
	printf("Wir benötigen dafür %i Bytes im Speicher\n", i+1);

	text = realloc(text, i+1); //Arbeitsspeicher mit der kleinstmöglichsten Größe neu abspeichern

	printf("Dein Text ist: %s\n", text);


	//Speicher muss freigegeben werden!
	free(text);
	return 0;
}
