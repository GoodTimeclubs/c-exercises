#include <stdio.h>
#include <stdlib.h>

int readint(){
    int out = 0;
    int puffergroesse = 10;
    int i = 0;
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
        if (eingegebene_zahl != '\n' && eingegebene_zahl >= '0' && eingegebene_zahl <= '9') //Überprüfung ob Zahl
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
    } while (eingegebene_zahl != '\n'); //solange bis Enter eingegeben wird
    puffer = realloc(puffer, eingabepos); //array auf tatsächliche Zahlenlänge anpassen
    
    while(puffer[i] != '\0') //umwandlung von Puffer in Output Zahl
    {
        out = out * 10;
        out = out + puffer[i];
        i++;
    }
    
    return out;
}
