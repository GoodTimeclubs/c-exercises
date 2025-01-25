#include <stdio.h>

int main (){

	double darlehen = 0;
	double zinssatz = 0;
	int dauer = 0;
	double restschuld = 0;
	double zinsen = 0;
	double tilgung = 0;
	double annuitaet = 0;
	double q = 0;
	long double qHochN = 0;
	int i = 0;

	printf("Wie hoch ist das Darlehen? ");
	scanf("%lf", &darlehen);

	printf("Zu wieviel %% wird verzinst? ");
	scanf("%lf" , &zinssatz);

	printf("Wie viele Jahre Rueckzahldauer? ");
	scanf("%d" , &dauer);


	printf("Jahr\tRestschuld\tZinsen\t\tTilgung\t\tAnnuitaet\n");
	
	q = 1 + (zinssatz / 100);	
	qHochN = q;

	
	for(i = 1; i < dauer; i++){

		//Berechnung qHochN
		qHochN = qHochN * q;	
	
	}
	

	// Berechnung annuität
	annuitaet = (darlehen*qHochN*(q-1))/(qHochN-1);
		
	
	//Berechnung des ersten Jahres
	restschuld = darlehen;
	zinsen = restschuld * (zinssatz/100);
	tilgung = annuitaet - zinsen;
	

	//Ausgabe des ersten Jahres
	printf("%d\t%.2lf\t%.2lf\t\t%.2lf\t%.2lf\n", 1, restschuld, zinsen, tilgung, annuitaet);


	for(i = 1; i < dauer; i++){
		// Berechnung der Folgejahre
		restschuld = restschuld - tilgung;
		zinsen = restschuld * (zinssatz/100);
		tilgung = annuitaet - zinsen;
		
		//Ausgabe der Folgejahre
		printf("%d\t%.2lf\t%.2lf\t\t%.2lf\t%.2lf\n", i+1, restschuld, zinsen, tilgung, annuitaet);

	}

	return 0;
	//Ergebnis zu Fragestellung: Zinsen im letzten Jahr = 2161.58

}
