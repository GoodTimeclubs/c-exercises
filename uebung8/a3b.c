#include <stdio.h>
#include <stdlib.h>
#include "readtext.h"
//Module importieren
#include "a301.h"
#include "a302.h"
#include "a303.h"
#include "a304.h"
#include "a305.h"
#include "a306.h"
#include "a307.h"
#include "a308.h"
#include "a309.h"
#include "a310.h"
#include "a311.h"
#include "a312.h"
#include "a313.h"
#include "a314.h"
#include "a315.h"
#include "a316.h"

int main(){
    
    int choice = 0;

    printf("\n\n\n##############################################\n");
    printf("#              GoodTime Industries           #\n");
    printf("##############################################\n\n\n\n");

    printf("Bitte geben Sie einen Text ein:\n");

    char* input1 = readtext();
    
    printf("Was möchten Sie damit tun?\n\n");
    printf("1  = zaehlen der Anzahl der Zeichen\n");
    printf("2  = zaehlen der Anzahl eines Zeichens\n");
    printf("3  = in neuen Speicherbereich kopieren\n");
    printf("4  = Eingabe spiegeln\n");
    printf("5  = ASCII Wert jedes Zeichens um 1 erhöhen\n");
    printf("6  = Palindrom erzeugen\n");
    printf("7  = alle Zeichen außer Vokale kopieren\n");
    printf("8  = Kleinbuchstaben in Großbuchstaben\n");
    printf("9  = Großbuchstaben in Kleinbuchstaben\n");
    printf("10 = ROT13 verschlüsseln\n");
    printf("11 = Caesar verschlüsseln\n");
    printf("12 = alphabetisch vergleichen\n");
    printf("13 = Eingaben zusammenführen (hintereinander)\n");
    printf("14 = Eingaben zusammenführen (Zeichen abwechselnd)\n");
    printf("15 = Eingabe durchsuchen\n");
    printf("16 = teil der Eingabe kopieren\n");

    scanf("%d", &choice);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if(choice == 1)
    {
	    a301(input1);        
    }

    if(choice == 2)
    {
	    a302(input1);        
    }

    if(choice == 3)
    {
	    a303(input1);        
    }

    if(choice == 4)
    {
	    a304(input1);        
    }
    
    if(choice == 5)
    {
	    a305(input1);        
    }

    if(choice == 6)
    {
	    a306(input1);        
    }

    if(choice == 7)
    {
	    a307(input1);        
    }

    if(choice == 8)
    {
	    a308(input1);        
    }

    if(choice == 9)
    {
	    a309(input1);        
    }

    if(choice == 10)
    {
	    a310(input1);        
    }

    if(choice == 11)
    {
	    a311(input1);        
    }

    if(choice == 12)
    {
	    a312(input1);        
    }

    if(choice == 13)
    {
	    a313(input1);        
    }

    if(choice == 14)
    {
	    a314(input1);        
    }

    if(choice == 15)
    {
	    a315(input1);        
    }

    if(choice == 16)
    {
	    a316(input1);        
    }
	
    free(input1);
}
