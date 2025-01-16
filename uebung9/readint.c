#include <stdlib.h>
#include <stdio.h>

int readint() {
	int zahl = 0;
	int vorzeichen = 1;	// 1 fuer positiv, -1 fuer negativ
	char zeichen = getchar();
	if (zeichen=='-') {	// Minuszeichen merken
		vorzeichen = -1;
		zeichen = getchar();
	}
	if (zeichen=='+') {	// Pluszeichen ignorieren
		zeichen = getchar();
	}
	// Ziffern parsen und Zahl berechnen
	while (zeichen>='0' && zeichen<='9') {
		zahl = zahl*10 + zeichen-'0';
		zeichen = getchar();
	}
	// Tastaturpuffer leeren bis Enter (optional)
	while (zeichen != '\n') {
		zeichen=getchar();
	}
	return zahl*vorzeichen;
}