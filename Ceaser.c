/**
 * Ceaser Cipher - Project 1
 * A ceaser cipher the creates a cipher based on the
 * provided key. This key can be used to encrypt or decrypt
 * the message.
 **/

#include <stdio.h>


// Function prototypes.
void GetEncryptKey();
char* RemoveDuplicates(char Word[]);
int TargetFound(char charArray[], int num, char target);
void InitializeEncryptArray(char Key[], char Encrypt[]);
void InitializeDecryptArray(char Encrypt[], char Decrypt[]);
void ProcessInput(FILE* Inf, FILE* Outf, char Substitute[]);

int main() {

	// Array containing every letter in the alphabet.
	char Alpha[26];

	// Fill the alpha array with every letter form the alphabet.
	for (char i = 'A'; i <= 'Z'; i++)
		Alpha[i - 'A'] = i;

	GetEncryptKey();

	// Print out alphabet
	for (int i = 0; i < 26; i++)
		printf("%c\n", Alpha[i]);

	printf("Hello World\n %c\n", Alpha[1]);
	return 0;
}

void GetEncryptKey() {
	printf("Please enter key");
}


/**
 * Removes any duplicate letters from the key specified by the user.
 * In order to generate a cipher key duplicate letters must be removed.
 **/
char* RemoveDuplicates(char Word[]) {

}


/**
 * Search the first num characters in array charArray for character target
 * return a non-zero integer if found, otherwise, return 0
 **/
int TargetFound(char charArray[], int num, char target) {

}


/**
 * Initialize the encrypt array with appropriate cipher letters
 * according to the given key.
 **/
void InitializeEncryptArray(char Key[], char Encrypt[]) {

}


/**
 * Initialize the decrypt array with appropriate substitute letters
 * based on the encrypt array.
 **/
void InitializeDecryptArray(char Encrypt[], char Decrypt[]) {

}


/**
 * Process data from the input file and write the result to the output file
 * pass the encrypt array to parameter substitute if encryption is inteded
 * pass the decrypt array to parameter substitute if decryption is inteded.
 **/
void ProcessInput(FILE* Inf, FILE* Outf, char Substitute[]) {

}


