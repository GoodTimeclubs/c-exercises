#include <stdio.h>

void inc (int* adr){

    *adr = *adr +1;

}

int main () {
    int i = 42;
    printf("%i\n", i);
    inc(&i);
    printf("%i\n", i);

}