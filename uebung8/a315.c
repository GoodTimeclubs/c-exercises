#include <stdlib.h>
#include <stdio.h>
#include "readtext.h"
#include "a315.h"

void a315(char *input)
{
    // Variablendefinition
    int resulttemp = 0;
    int resultpos = 0;
    int length = 0;
    int slength = 0;
    int i = 0;

    // Benutzereingabe
    printf("Nach welcher Zeichenkette soll gesucht werden?\n");
    char *search = readtext();

    // Berechnen der Länge es zu suchenden Strings
    while (search[slength] != '\0')
    {
        slength++;
    }

    // Jedes Zeichen der eingabe durchgehen
    while (input[length] != '\0')
    {
        printf("DEBUG - Durchsuche den %d. Buchstaben %c \n", length, input[length]);

        // wenn aktueller Buchtabe der selbe ist wie der erste des gesuchten Strings
        while (input[length] == search[i])
        {
            printf("DEBUG - Treffer an der %d. Stelle bei Buchstebe %c \n", length, input[length]);

            resulttemp = length;
            printf("DEBUG - resulttemp auf %d gesetzt.\n", resulttemp);

            // vorzeitige Erhöhung der Zähler, damit noch in der While schleife der Nachfolger der Strings geprüft werden kann
            i++;
            length++;

            if (search[i] == '\0') // Wenn der zu suchende String aufhört
            {
                if (!(i == slength)) // und nicht der ganze zu suchende String gefunden wurde
                {
                    resulttemp = 0; // zurücksetzen des resulttemp zählers
                    printf("DEBUG - resulttemp in if statement auf %d gesetzt.\n", resulttemp);
                }
            }

            if (search[i] == '\0' && resultpos == 0) // Wenn der zu suchende String aufhört und resultpos noch bei 0 ist (wird nur einmalig ausgeführt)
            {
                resultpos = resulttemp; // den Wert von resulttemp in resultpos speichern
                printf("DEBUG - Wert %d in resultpos geschrieben.\n", resulttemp);
            }

            if (!(input[length] == search[i])) // Vorzeitige überprüfung der Bedingung der Whileschleife
            {
                length = length - 1; // wenn Bedingung nicht mehr zutrifft, dann das length++ rückgängig machen, damit kein Buchstabe übersprungen wird
            }
        }

        i = 0;
        length++;
    }

    resultpos = resultpos - (slength - 1); // länge des zu suchenden strings von resultpos abzieben, um den Anfangspunkt zu erhalten

    // Ausgabe
    if (resultpos <= 0)
    {
        printf("Die Zeichenkette \"%s\" wurde nicht in \"%s\" gefunden.\n", search, input);
    }
    else
    {
        printf("Die Zeichenkette wurde an der %d. Stelle gefunden.\n", resultpos + 1);
    }
    free(search);
}