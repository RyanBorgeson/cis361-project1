// Ceaser Cipher - Project 1
// A ceaser cipher the creates a cipher based on the
// provided key. This key can be used to encrypt or decrypt
// the message.

#include <stdio.h>

int main() {

	// Array containing every letter in the alphabet.
	char Alpha[26];

	// Fill the alpha array with every letter form the alphabet.
	for (char i = 'A'; i <= 'Z'; i++)
		Alpha[i - 'A'] = i;

	// Print out alphabet
	for (int i = 0; i < 26; i++)
		printf("%c\n", Alpha[i]);

	printf("Hello World\n %c\n", Alpha[1]);
	return 0;
}

