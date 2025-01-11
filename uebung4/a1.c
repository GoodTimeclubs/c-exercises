#include <stdio.h>

int main (){

	int abstand = 0;
	// Variable für Benutzereingaben
	int eingabe = 0;
	int eingabeZwei = 0;

	// Einlesen der Benutzereingabe
	printf("\nBitte geben Sie die erste Zahl ein:\n");
	scanf("%d",&eingabe);

	//Überprüfen, ob Benutzereingabe positiv ist
	if(eingabe > 0){
	
		printf("Die Zahl %d ist positiv.\n", eingabe);
	
	//Wenn nicht dann überprüfung ob Zahl negativ ist
	} else if (eingabe < 0) {
		
		printf("Die Zahl %d ist negativ.\n", eingabe);
	
	//Schlussfolgerung, dass die Zahl Null ist
	} else {

		printf("Die Zahl %d ist die Null.\n", eingabe);

	}

	

	//Überprüfung ob Zahl in Zahlenbereich liegt
	if(eingabe > -128 && eingabe < 127){

		printf("Diese Zahl könnte auch mit dem Datentyp char gespeichert werden.\n");	

	}
	

	//Überprüfung, ob Zahl gerade
	if(eingabe % 2 == 0){

		printf("Es handelt sich hierbei um eine gerade Zahl\n");

	} else {

		printf("Es handelt sich um eine ungerade Zahl\n");
	
	}




	//einlesen der zweiten Benutzereingabe
	
	printf("\nBitte geben Sie die zweite Zahl ein:\n");
	scanf("%d", &eingabeZwei);


	//Vergleich zwischen dem beiden Benutzereingaben und berechnen des Abstands
	if( eingabe < eingabeZwei ) {

		printf("Die zweite Zahl ist größer als die erste Zahl.\n");
		
		abstand = eingabeZwei - eingabe;	

	} else if ( eingabe > eingabeZwei ) {

		printf("Die zweite Zahl ist kleiner als die erste Zahl.\n");
	
		abstand = eingabe - eingabeZwei;

	} else {

		printf("Beide Zahlen sind gleich.\n");
	
		abstand = 0;

	}

	//Ausgabe des Abstands
		
	printf("Der Abstand zwischen den Zahlen beträgt %d .\n", abstand);
}
