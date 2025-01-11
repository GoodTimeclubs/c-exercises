#include <stdio.h>

int main() {
	char vorname[] = "Karl";
	char nachname[] = "Schlauberger";
	char studienfach[] = "HIS (High Integrity Systems)";
	

	printf("\nHier folgt eine kleine Tabelle mit \"\\\"-Zeichen als Spalten-Trenner\n\n");
	printf("Vorname\t\\ Nachname\t\\ Studienfach\t\t\t\\\n");
	printf("%s\t\\ %s\t\\ %s\t\\\n", vorname, nachname, studienfach);
	printf("\n");
	return 0;
}
