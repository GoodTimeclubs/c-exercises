#include <stdio.h>
#include <stdlib.h>

void eingabeaufforderung_info(){
	printf("Es ist nun eine Benutzereingabe erforderlich.\n");
}

int eingabeaufforderung_zk (char* eingabeZk){
	int charCheck = 1; 
	int i = 0;
	int funcCheck = 0; //Rekursive Funktion nicht ausgelöst
	eingabeaufforderung_info();
	printf("Bitte geben sie eine Zeichenkette ein: (\"x\" für erneuter Versuch)");
	while (charCheck && funcCheck != 1){
		scanf("%s", eingabeZk);
		if(eingabeZk[0] == 'x' && eingabeZk[1] == '\0') {
			funcCheck = eingabeaufforderung_zk(eingabeZk);
		}else{
			charCheck = 0;
		}
	}
	return 1;
}

int eingabeaufforderung_int (){
	int eingabe = 0;
	eingabeaufforderung_info();
	printf("Bitte geben sie eine ganze Zahl ein: ");
	scanf("%i", &eingabe);
	return eingabe;
}

void ausgabeInt  (int zahl){
	printf("Die Zahl lautet: %i\n", zahl);
}

void ausgabeZk  (char* text){
	printf("Die Zeichenkette lautet: %s\n", text);
}

int main (){
	int eingabeZkCheck = 0;
	int eingabeInt = 0;
	char eingabeZk[50];


	//Zahlen einlesen bis eine Positive eingegeben wird
	do{
		eingabeInt = eingabeaufforderung_int();

	}while(eingabeInt < 0);

	// Zeichenkette einlesen, bis sie nicht leer ist
	eingabeaufforderung_zk(eingabeZk);
	ausgabeInt(eingabeInt);
	ausgabeZk(eingabeZk);
	return 0;
}
