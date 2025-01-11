#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eingabeaufforderung_info(){
        printf("Es ist nun eine Benutzereingabe erforderlich.\n");
}

void eingabeaufforderung_zk (){
        char eingabeZk [50];
        int charCheck = 1;
        eingabeaufforderung_info();
        printf("Bitte geben sie eine Zeichenkette ein: ");
        while (charCheck){
                if(fgets(eingabeZk, sizeof(eingabeZk), stdin) != NULL) {
                        if (eingabeZk[0] != '\n' && strlen(eingabeZk) > 1) { // Prüfen, ob die Eingabe nicht leer ist
                                charCheck = 0;
                        } else {
                                printf("Die Eingabe darf nicht leer sein. Bitte erneut eingeben: ");
                        }
                }
        }
}

int eingabeaufforderung_int (){
        char eingabeStr[50];
        int eingabe = 0;
        eingabeaufforderung_info();
        printf("Bitte geben sie eine ganze Zahl ein: ");
        while (1) {
                if (fgets(eingabeStr, sizeof(eingabeStr), stdin) != NULL) {
                        char *endptr;
                        eingabe = strtol(eingabeStr, &endptr, 10);
                        if (endptr != eingabeStr && *endptr == '\n') {
                                break;
                        } else {
                                printf("Ungültige Eingabe. Bitte geben Sie eine gültige ganze Zahl ein: ");
                        }
                }
        }
        return eingabe;
}

int main (){
        int eingabeInt = 0;

        // Zahlen einlesen bis eine Positive eingegeben wird
        do{
                eingabeInt = eingabeaufforderung_int();
                if (eingabeInt < 0) {
                        printf("Die Zahl darf nicht negativ sein. Bitte erneut eingeben.\n");
                }
        }while(eingabeInt < 0);

        // Zeichenkette einlesen, bis sie nicht leer ist
        eingabeaufforderung_zk();

        return 0;
}

