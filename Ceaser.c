/**
 * Ceaser Cipher - Project 1
 * A ceaser cipher the creates a cipher based on the
 * provided key. This key can be used to encrypt or decrypt
 * the message.
 * @Author Ryan Borgeson
 **/

#include <stdio.h>


/* Function prototypes */
char* RemoveDuplicates(char Word[]);
int TargetFound(char charArray[], int num, char target);
char* InitializeEncryptArray(char Key[], char Encrypt[]);
void InitializeDecryptArray(char Encrypt[], char Decrypt[]);
void ProcessInput(FILE* Inf, FILE* Outf, char Substitute[]);

int main(int argc, char *argv[]) {
	// Reverse alpahbet that is used to create the encryption array.
	char ReverseAlpha[26] = "ZXYWVUTSRQPONMLKJIHGFEDCBA",
		 ForwardAlpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWYX";
	
	// Remove duplicate characters from both the cipher key and
	// then append cipher key to encryption array.
	char *CipherKey = RemoveDuplicates(argv[2]),
		 *EncryptionArray = InitializeEncryptArray(CipherKey, ReverseAlpha);
	

	printf("Cipher Key: %s\nEncryption Array: %s\n", CipherKey, EncryptionArray);
	return 0;
}

/**
 * Removes any duplicate letters from a word.
 * In order to generate a cipher key duplicate letters must be removed.
 * Also, this is used when creating the encrypted alpahbet pattern.
 * @param Word The character array to have duplicates removed.
 * @return Returns a new character array with duplicate characters removed.
 **/
char* RemoveDuplicates(char Word[]) {
	// Dynamically allocate space for the new key character array.
	// This will be returned by the function.
	char *NewWord = malloc(strlen(Word) * sizeof(char));
	
	int i = 0,									// Word argument iterator index.
		n = 0,									// New Key iterator index.
		LetterExists = 0,						// Letter exists in new key flag.
		NewKeySize = (int)strlen(NewWord);		// Size of New Key character array.
		
	// Iterate through each letter in the word to determine if it exists
	// within the new character array. If not, add it to the new key.
	for (int i = 0; i < (int)strlen(Word); i++) {
		for (int n = 0; n < NewKeySize; n++) {
			if (NewWord[n] == toupper(Word[i]))
				LetterExists = 1;
		}
		
		// If the character does not exist in the new key then add it.
		if (!LetterExists) {
			NewWord[NewKeySize] = toupper(Word[i]);
			NewKeySize++;
		}
		LetterExists = 0;
	}
	
	return NewWord;
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
 * @param Key The cipher key with removed duplicate characters.
 * @param Encrypt The encryption key based on the cipher.
 * @return Returns the encryption array with removed duplicate characters.
 **/
char* InitializeEncryptArray(char Key[], char Encrypt[]) {
	// Calculate length of Key and Encrypt for the new combined array.
	int KeyLength = strlen(Key),
		EncryptLength = strlen(Encrypt);
		
	// Allocate space for the new combined array.
	char* CombinedArray = malloc((KeyLength + EncryptLength) * sizeof(char));

	// Copy the contents of the Key array and Encrypt array to
	// memory locations that were allocated for the CombinedArray.
	memcpy(CombinedArray, Key, KeyLength * sizeof(char));
	memcpy(CombinedArray + KeyLength, Encrypt, EncryptLength * sizeof(char));
	
	// Lastly, remove any duplicate letters.
	return RemoveDuplicates(CombinedArray);
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


