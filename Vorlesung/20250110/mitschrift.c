#include <stdio.h>
#include <stdlib.h>

struct Tripel {
    int a;
    char buchstabe;
    int b;
}; //Hier Semikolon

int main (){
    int x = 42;
    char zeichen = 'a';
    struct Tripel bsp;
    struct Tripel foo;

    bsp.a = 17;
    bsp.buchstabe = 'x';
    bsp.b = -12;

    foo.buchstabe = bsp.buchstabe;

    return 0;
}