#include <stdio.h>

int main () {

	int zahl = 0;
	int carry = 0;
	int l = 0;
	int i = 0;	

	printf("Bitte gebe eine Zahl ein: ");
	scanf("%i", &zahl);

	carry = zahl%10;

	printf("%i\n", carry);
	

	printf("\n");

}
