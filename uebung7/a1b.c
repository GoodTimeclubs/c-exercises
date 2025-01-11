#include <stdio.h>
#include <stdlib.h>

void eingabeaufforderung_info(){
	printf("Es ist nun eine Benutzereingabe erforderlich.\n");
}

int eingabeaufforderung_zk (char* eingabe){
	eingabeaufforderung_info();
	scanf("%s", eingabe);
}

int main (){
	char eingabe[200];
	eingabeaufforderung_zk(eingabe);

	return 0;
}
