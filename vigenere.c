/**
 * Description : Vigenère cipher algorithm
 * Author : Anupam Saikia (GAU-C-17/064)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to generate the full key
char *generateKey(char *str, char *key)
{
    size_t strLength = strlen(str);
    size_t keyLength = strlen(key);
    char *generatedKey = (char *)malloc(sizeof(char) * strLength);

    for (int i = 0, j = 0; i < strLength; i++)
    {
        j = i % keyLength;
        generatedKey[i] = key[j];
    }
    return generatedKey;
}

/**
 * Function to encrypt plaintext using Vigenère cipher.
 * Returns the ciphertext
 */
char *vigenereEncrypt(char *plainText, char *key)
{
    size_t size = strlen(plainText);
    char *cipherText = (char *)malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
    {
        char p = toupper(plainText[i]);
        char k = toupper(key[i]);

        // Process the alpabets 'A'=65 'Z'=90
        if (p >= 65 && p <= 90)
            cipherText[i] = ((p + k) % 26) + 65;

        // Other characters will not change
        else
            cipherText[i] = plainText[i];
    }
    return cipherText;
}

/**
 * Function to decrypt ciphertext using Vigenère cipher
 * Returns the plaintext
 */
char *vigenereDecrypt(char *cipherText, char *key)
{
    size_t size = strlen(cipherText);
    char *plainText = (char *)malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
    {
        char c = toupper(cipherText[i]);
        char k = toupper(key[i]);
        // Process the alpabets 'A'=65 'Z'=90
        if (c >= 65 && c <= 90)
            plainText[i] = ((c - k + 26) % 26) + 65;

        // Other characters will not change
        else
            plainText[i] = cipherText[i];
    }
    return plainText;
}

// Used to clear input buffer
void clearBuffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    char str[100], key[100], option = '0';
    printf("1. Encrypt\n2. Decrypt\nEnter option [1-2] : ");
    scanf("%c", &option);

    switch (option)
    {
    case '1':
        printf("Enter plaintext : ");
        clearBuffer();
        fgets(str, 100, stdin);
        printf("Enter keyword : ");
        scanf("%s", key);
        printf("Ciphertext : %s", vigenereEncrypt(str, generateKey(str, key)));
        break;
    case '2':
        printf("Enter ciphertext : ");
        clearBuffer();
        fgets(str, 100, stdin);
        printf("Enter keyword : ");
        scanf("%s", key);
        printf("Plaintext : %s", vigenereDecrypt(str, generateKey(str, key)));
        break;
    default:
        printf("Enter correct option\n");
        break;
    }

    return 0;
}
