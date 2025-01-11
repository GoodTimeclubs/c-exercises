#include<stdio.h>

int main () {

	char alphabet[26];
	char kalphabet[26];
	int i = 0;
	
	alphabet[0] = 'A';
	kalphabet[0] = 'a';


	for(i=0; i<25; i++){
		
		alphabet[i+1] = alphabet[i] + 1;
		kalphabet[i+1] = kalphabet[i] + 1;
	}
	alphabet[26] = '\0';
	kalphabet[26] = '\0';

	printf("%s%s\n", alphabet, kalphabet);



}
