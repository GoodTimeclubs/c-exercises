#include <stdio.h>

int iplusplus(int* i){
    *i = *i +1;
    return *i-1;
    
}

int main (){
    int i = 0;
    printf("i=%d\n", iplusplus(&i) ); // Ausgabe: i=0
    printf("i=%d\n", iplusplus(&i) ); // Ausgabe: i=1
    printf("i=%d\n", iplusplus(&i) ); // Ausgabe: i=2
}