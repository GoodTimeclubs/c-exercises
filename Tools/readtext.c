#include <stdlib.h>
#include <stdio.h>

char *readtext()
{
    int puffergroesse = 10;
    char *puffer = malloc(puffergroesse);
    if (puffer == NULL)
    {
        printf("\nFEHLER! Speicherplatz konnte nicht reserviert werden!\n");
        return puffer;
    }
    int eingabepos = 0;
    char eingegebenes_zeichen;
    do
    {
        eingegebenes_zeichen = getchar();
        if (eingegebenes_zeichen != '\n')
        {
            puffer[eingabepos] = eingegebenes_zeichen;
            eingabepos++;
            if (eingabepos == puffergroesse)
            {
                puffergroesse = puffergroesse + 10;
                puffer = realloc(puffer, puffergroesse);
                if (puffer == NULL)
                {
                    printf("\nFEHLER! Speicherplatz konnte nicht erweitert werden!\n");
                    return puffer;
                }
            }
        }
    } while (eingegebenes_zeichen != '\n');
    puffer[eingabepos] = '\0';
    puffer = realloc(puffer, eingabepos + 1);
    return puffer;
}
