#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

char * encrypt(string plain, int cipher_key);

int main(int argc, string argv[])
{
    // Checks if there is a command line agrument passed for Key
    if (argc != 2)
    {
        printf("Missing Key agrument for Caesar cipher\n");
        return 1;
    }

    // Set key
    int key = atoi(argv[1]);

    printf("plaintext:");
    string plaintext = get_string();

    // Encrypt plaintext
    char *ciphertext;
    ciphertext = encrypt(plaintext, key);
    printf("ciphertext:%s\n", ciphertext);

    return 0;
}

// Returns plaintext encrypted with string
char * encrypt(string plain, int cipher_key)
{
    int text_length = strlen(plain);
    int shift;
    char *cipher = malloc(text_length);

    // Loop through user input
    for (int i = 0; i < text_length; i++)
    {
        // Only shift letters
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                // Shift plaintext by key
                shift = (plain[i] - 'A' + cipher_key) % ALPHABET_SIZE;
                // Uppercase case
                cipher[i] = 'A' + shift;
            }
            else
            {
                // Shift plaintext by key
                shift = (plain[i] - 'a' + cipher_key) % ALPHABET_SIZE;
                // Lowercase case
                cipher[i] = 'a' + shift;
            }
        }
        else
        {
            cipher[i] = plain[i];
        }
    }

    return cipher;
}