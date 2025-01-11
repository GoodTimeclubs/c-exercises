#include <stdio.h>
#include <stdlib.h>

void eingabeaufforderung_info(){
	printf("Es ist nun eine Benutzereingabe erforderlich.\n");
}

void eingabeaufforderung_zk (){
	char eingabeZk [50];
	int charCheck = 1;
	eingabeaufforderung_info();
	printf("Bitte geben sie eine Zeichenkette ein: (X für Abbruch)");
	while (charCheck){
		if(fgets(eingabeZk, sizeof(eingabeZk), stdin) != NULL) {
			charCheck = 0;

		}
	}
	
}

int eingabeaufforderung_int (){
	int eingabe = 0;
	eingabeaufforderung_info();
	printf("Bitte geben sie eine ganze Zahl ein: ");
	scanf("%i", &eingabe);
	return eingabe;
}

int main (){
	int eingabeZkCheck = 0;
	int eingabeInt = 0;


	//Zahlen einlesen bis eine Positive eingegeben wird
	do{
		eingabeInt = eingabeaufforderung_int();

	}while(eingabeInt < 0);

	// Zeichenkette einlesen, bis sie nicht leer ist
	eingabeaufforderung_zk();

	return 0;
}
