#include <stdio.h>
#include <stdlib.h>

int readint(){
    int out = 0;
    int puffergroesse = 10;
    int i = 0;
    int negativ = 0;
    int* puffer = malloc(puffergroesse);

    //Fehlerüberprüfung bei Speicherplatzreservierung
    if (puffer == NULL)
    {
        printf("\nFEHLER! Speicherplatz konnte nicht reserviert werden!\n");
    }
    int eingabepos = 0;
    char eingegebene_zahl;
    do
    {
        eingegebene_zahl = getchar(); //Zeichen Einlesen

        if (eingegebene_zahl == '-' && eingabepos == 0)// erkennung ob Eingabe negativ ist
        {
            negativ = 1;
            eingegebene_zahl = getchar(); //Zeichen für 1. Stelle Einlesen
        }

        if (eingegebene_zahl == '+' && eingabepos == 0) eingegebene_zahl = getchar(); //Zeichen für 1. Stelle Einlesen und + ignorieren

        if (eingegebene_zahl >= '0' && eingegebene_zahl <= '9') //Überprüfung ob Zahl
        {
            puffer[eingabepos] = eingegebene_zahl -48; //umwandlung von ascii zu einer Zahl
            eingabepos++;
            if (eingabepos == puffergroesse) 
            {
                puffergroesse = puffergroesse + 10;
                puffer = realloc(puffer, puffergroesse);//Speicher erweitern, wenn dieser nur noch eine freie Stelle hat
                
                //Fehlerüberprüfung bei Speicherplatzreservierung
                if (puffer == NULL)
                {
                    printf("\nFEHLER! Speicherplatz konnte nicht erweitert werden!\n");
                }
            }
        }
    } while (eingegebene_zahl >= '0' && eingegebene_zahl <= '9'); //solange eine Zahl eingegeben wird
    puffer = realloc(puffer, eingabepos+1); //array auf tatsächliche Zahlenlänge anpassen
    
    while(puffer[i] != '\0') //umwandlung von Puffer in Output Zahl
    {
        out = out * 10;
        out = out + puffer[i];
        i++;
    }

    if(negativ == 1) //wenn eingabe negativ ist, ausgabe auch negativ
    {
        out = 0 - out;
    }
    
    return out;
}
