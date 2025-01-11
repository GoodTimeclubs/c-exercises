#include <stdio.h>
double einlesen (int i){
    double eingabe = 0;
        printf("Bitte geben sie die %i. Zahl ein: ",i+1);
        scanf("%lf", &eingabe);
    return eingabe;
}

double bmin (double* eingabe){
    int i = 0;
    double localmin = 0;
    for(i=0; i<10; i++){
        if(eingabe[i] < localmin || localmin == 0){
            localmin = eingabe[i];
        }
    }
    return localmin;
}

double bmax (double* eingabe){
    int i = 0;
    double localmax = 0;
    for(i=0; i<10; i++){
        if(eingabe[i] > localmax || localmax == 0){
            localmax = eingabe[i];
        }
    }
    return localmax;
}

double bavg (double* eingabe){
    int i = 0;
    double localavg = 0;
    for(i=0; i<10; i++){
        localavg = localavg + eingabe[i];
    }
    return localavg/10;
}

void ausgabe (double minimum, double maximum, double avg) {
    printf("Das Minimum ist %.2lf\n", minimum);
    printf("Das Maximum ist %.2lf\n", maximum);
    printf("Der Durchschnitt ist %.2lf\n", avg);
}


int main () {
    double eingabe[10] = {};
    double minimum = 0;
    double maximum= 0;
    double avg = 0;
    int i = 0;

    for (i = 0; i<10; i++){
        eingabe[i] = einlesen(i);
    }

    minimum = bmin(eingabe);
    maximum = bmax(eingabe);
    avg = bavg(eingabe);

    ausgabe(minimum, maximum, avg);
}