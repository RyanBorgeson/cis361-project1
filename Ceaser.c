/**
 * Ceaser Cipher - Project 1
 * A ceaser cipher that creates a cipher based on the
 * provided key. This key can be used to encrypt or decrypt
 * the message in a file.
 * @Author Ryan Borgeson
 * @Date 10/5/2016
 **/

#include <stdio.h>

#define ALPHA_SIZE 26

/* Function prototypes */
char* RemoveDuplicates(char Word[]);
void InitializeEncryptArray(char Key[], char Encrypt[]);
void InitializeDecryptArray(char Encrypt[], char Decrypt[]);
void ProcessInput(FILE* Inf, FILE* Outf, char Substitute[]);

int main(int argc, char *argv[]) {
	
	// Determine if enough arguments were passed into the program. 
	// Display error message if appropriate.
	if (argc != 5) {
		printf("Not enough arguments were specified.\n");
		printf("Encrypt Command Format: Ceaser 0 <CIPHER> <FILE IN> <FILE OUT>\n");
		printf("Decrypt Command Format: Ceaser 1 <CIPHER> <FILE IN> <FILE OUT>\n");
		return 0;
	}
		 
	// Declare Encrypt and Decrypt arrays.
	char Encrypt[ALPHA_SIZE], Decrypt[ALPHA_SIZE];
	
	// Remove duplicate characters from the cipher key.
	char *CipherKey = RemoveDuplicates(argv[2]);
	
	// Encrypt or decrypt option.
	int Choice = atoi(argv[1]);
	
	// Initialize both Encrypt and Decrypt arrays with
	// the proper characters.
	InitializeEncryptArray(CipherKey, Encrypt);
	InitializeDecryptArray(Encrypt, Decrypt);
			 
	 // Specify the input file and the output file.
	FILE *FileIn, *FileOut;
	FileIn = fopen(argv[3], "r");
	FileOut = fopen(argv[4], "w");
		  
	// Determine whether to encrypt or decrypt the file depending on
	// what the user has specified.
	if(!Choice) {
		ProcessInput(FileIn, FileOut, Encrypt);
	} else {
		ProcessInput(FileIn, FileOut, Decrypt);
	}
    
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
 * Initialize the encrypt array with appropriate cipher letters
 * according to the given key.
 * @param Key The cipher key with removed duplicate characters.
 * @param Encrypt The encryption array based on the cipher.
 **/
void InitializeEncryptArray(char Key[], char Encrypt[]) {
	// Calculate length of Key array.
	int KeyLength = strlen(Key);
		
	// Allocate space for a temperary array.
	char* Temp = malloc((KeyLength + ALPHA_SIZE) * sizeof(char));

	// Copy the contents of the Key array and append the alphabet removing
	// any character after ALPHA_SIZE.
	memcpy(Temp, Key, KeyLength);
	memcpy(Temp + KeyLength, "ZXYWVUTSRQPONMLKJIHGFEDCBA", ALPHA_SIZE * sizeof(char));
	
	// Lastly, remove any duplicate letters and copy to encrypt array.
	Temp = RemoveDuplicates(Temp);
	memcpy(Encrypt, Temp, ALPHA_SIZE * sizeof(char));
	
	// Free temperary memory.
	free(Temp);
}


/**
 * Initialize the decrypt array with appropriate substitute letters
 * based on the encrypt array.
 * @param Encrypt The encryption array.
 * @param Decrypt Creates the contents of the decrypt array.
 **/
void InitializeDecryptArray(char Encrypt[], char Decrypt[]) {
	for (int i = 0; i < ALPHA_SIZE; i++) {
		Decrypt[Encrypt[i] - 'A'] = i + 'A';
	}
	Decrypt[ALPHA_SIZE] = '\0';
}


/**
 * Process data from the input file and write the result to the output file
 * pass the encrypt array to parameter substitute if encryption is intended
 * pass the decrypt array to parameter substitute if decryption is intended.
 * @param FileIn The file that will be read and encrypted.
 * @param FileOut File containing the encrypted data.
 * @param Substitute The encrypt or decrypt array.
 **/
void ProcessInput(FILE* FileIn, FILE* FileOut, char Substitute[]) {

	// Holds the newly read character.
	int ch;

	// Determine if either file exists. If not, display an error.
	if (FileIn == NULL || FileOut == NULL) {
		printf("Unable to open specified file.\n");
		return NULL;
	}

	// Loop through entire contents of the file, encrypt the contents, 
	// and output them to the new file.
    while ((ch = fgetc(FileIn)) != EOF) {
		if (!isalpha(ch)) {
			fprintf(FileOut, "%c", ch);
		} else {
			// Account for both upper and lower case in the file.
			if (islower(ch)) {
				fprintf(FileOut, "%c", Substitute[ch - 'A' - 32] + 32);
			} else {
				fprintf(FileOut, "%c", Substitute[ch - 'A']);
			}
		}
    }
}


