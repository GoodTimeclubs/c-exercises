#include <stdio.h>
#include <stdlib.h>

int main (){
    int start = 1000000;
    int i = 1;
    int temp = 0;
    for(i = 1; 1 < start; i++){
        temp = i;
        while(temp != 1){

            if(temp % 2 == 0){
                temp = temp / 2;
            }else{
                temp = temp * 3 + 1;
            }
        }    
    printf("Wert der Zahl: %d", temp);
    }
    return 0;
}