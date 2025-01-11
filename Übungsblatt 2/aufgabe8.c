#include <stdio.h>

int main () {
	
	signed char x = -12;
	unsigned char anzahl = 5;
	double kontostand = 543.21;
	signed char s1_ergebnis = (x+anzahl);
	double s2_ergebnis = (s1_ergebnis+kontostand);

	printf("Der Inhalt der Variablen x ist %i\n", x);
	printf("Der Inhalt der Variablen anzahl ist %i\n", anzahl);
	printf("Der Inhalt der Variablen kontostand ist %.2lf\n", kontostand);
	
	printf("\n");
	printf("Die Summe von x und anzahl ist %i\n", s1_ergebnis);
	printf("Die Summe von dem obigen Ergebnis und dem Kontostand ist %.2lf\n", s2_ergebnis);
	
	
	printf("\n");
	printf("Adressen im Arbeisspeicher:\n");
	printf("x\t\t: %p \t: %i\n", &x, &x);
	printf("anzahl\t\t: %p \t: %i\n", &anzahl, &anzahl);
	printf("kontostand\t: %p \t: %i\n", &kontostand, &kontostand);

	printf("\nErklärung\t: in Hex\t\t in dezimaler Form\n");
	
	return 0;


}
