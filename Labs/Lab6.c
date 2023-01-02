#include <stdio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char* encrypt(char *plaintext, int key) {

	//Get from pointer
	char* enc = (char*)malloc(strlen(plaintext)*sizeof(char));

	//Init integer counter to 0
	int i=0;


	//While plaintext is not NULL
	while(plaintext[i]!='\0'){

		//Init a variable of the current plaintext value
		int ch = plaintext[i];


		//If it is lowercase
		if('a'<=ch && ch<='z'){

			ch = (char)((plaintext[i]+key-65)%26 +65);

		}


		//If it is uppercase
		if('A'<=ch && ch<='Z'){

			ch = (char)((plaintext[i]+key-97)%26 +97);

		}


		//Append to char enc
		enc[i]=ch;

		//Increase counter by 1
		i += 1;

	}


	//We've broken from the while loop, so declare end
	enc[i]='\0' ;


	//Return our encrypted value
	return enc;


}

char* decrypt(char *ciphertext, int key) {

	//Get from pointer
	char* dec = (char*)malloc(strlen(ciphertext)*sizeof(char));

	//Init counter to 0
	int i = 0;


	//While ciphertext is not NULL
	while(ciphertext[i] != '\0') {

		//Init a variable of current ciphertext value
		int ch = ciphertext[i];


		//If it's lowercase
		if('a' <= ch && ch <= 'z') {

			ch = (char)('a'+((ch - 'a' - key + 26) % 26));


		}

		if('A' <= ch && ch <= 'Z') {

			ch = (char)('A'+((ch - 'A' - key + 26) % 26));

		}

		//Append to char dec
		dec[i]=ch;

		//Increase counter by 1
		i += 1;


	}

	//We've broken from the while loop, so declare end
	dec[i]='\0' ;


	//Return our decrypted value
	return dec;
}