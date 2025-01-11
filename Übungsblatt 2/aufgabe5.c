#include <stdio.h>

int main (){


	printf("Ergebnis 1:%d\n", (8/5)/2);
	//printf("%f", (8/5)/2); expects argument of type ‘double’, but argument 2 has type ‘int’
	printf("Ergebnis 2:%i\n", 8/(5/2));
	printf("Ergebnis 3:%f\n", (float) 5/2);
	printf("Ergebnis 4:%f\n", (float) (5/2));
	//printf("%d", (8/5.)/2); expects argument of type ‘int’, but argument 2 has type ‘double’
	printf("Ergebnis 5:%lf\n", (8/5)/2.);
	printf("Ergebnis 6:%d\n", (50/4)%2);
	printf("Ergebnis 7:%d\n", (50%4)/2);
	printf("Ergebnis 8:%d\n", 50%(4/2));

/*
	Ergebnis 1:0 --> Erste Klammer wird zu 1 und das /2 eigentlich zu 0,5. Wird daher als 0 ausgegeben.
	Ergebnis 2:4 --> 5/2 => 2 --> 8/2 => 4
	Ergebnis 3:2.500000 --> wird wegen dem (float) als Kommazahl dargestellt
	Ergebnis 4:2.000000 --> wird in der Klammer als int berechnet und hat daher die nachkommastellen nicht Berechnet.
	Ergebnis 5:0.500000 --> 8/5 => 1 1/2. => 0.5 , da durch den Punkt hinter der zwei die Zahl zu einem float wird.
	Ergebnis 6:0 --> 50/4 => 12   12%2 => 0 , da 12 durch 2 6.0 ergibt und durch das Prozentzeichen nur der Rest ausgegeben wird.
	Ergebnis 7:1 --> 50%4 => 2 , da 50 durch 4 einen Rest von 2 hat. 2/2 => 1
	Ergebnis 8:0 --> 4/2 => 2   50%2 => 0 , da 50 durch 2 keinen Rest hat.
*/
}
