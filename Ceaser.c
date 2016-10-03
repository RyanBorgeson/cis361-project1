/**
 * Ceaser Cipher - Project 1
 * A ceaser cipher the creates a cipher based on the
 * provided key. This key can be used to encrypt or decrypt
 * the message.
 * @Author Ryan Borgeson
 **/

#include <stdio.h>


// Function prototypes.
char* RemoveDuplicates(char Word[]);
int TargetFound(char charArray[], int num, char target);
void InitializeEncryptArray(char Key[], char Encrypt[]);
void InitializeDecryptArray(char Encrypt[], char Decrypt[]);
void ProcessInput(FILE* Inf, FILE* Outf, char Substitute[]);

int main(int argc, char *argv[]) {
	char *NoDupKey = RemoveDuplicates(argv[2]);
		

	printf("%s", NoDupKey);
	return 0;
}

/**
 * Removes any duplicate letters from the key specified by the user.
 * In order to generate a cipher key duplicate letters must be removed.
 * @param Word The encryption or decryption key passed in as an argument.
 * @return Returns a new character with duplicate characters removed.
 **/
char* RemoveDuplicates(char Word[]) {
	// Dynamically allocate space for the new key character array.
	// This will be returned by the function.
	char *NewKey = malloc(26);
	
	int i = 0,									// Word argument iterator index.
		n = 0,									// New Key iterator index.
		LetterExists = 0,						// Letter exists in new key flag.
		NewKeySize = (int)strlen(NewKey);		// Size of New Key character array.
		
	// Iterate through each letter in the word to determine if it exists
	// within the new character array. If not, add it to the new key.
	for (int i = 0; i < (int)strlen(Word); i++) {
		for (int n = 0; n < NewKeySize; n++) {
			if (NewKey[n] == toupper(Word[i]))
				LetterExists = 1;
		}
		
		// If the character does not exist in the new key then add it.
		if (!LetterExists) {
			NewKey[NewKeySize] = toupper(Word[i]);
			NewKeySize++;
		}
		LetterExists = 0;
	}
	
	return NewKey;
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


