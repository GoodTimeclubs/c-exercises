#include <stdio.h>

int main ()
{
    int arr[3];
    //printf("&arr[0] = %p, arr= %p\n", &arr[0], arr);

    int anzahl = sizeof(arr) / sizeof(arr[0]);
    printf("anzahl = %d\n", anzahl );
}