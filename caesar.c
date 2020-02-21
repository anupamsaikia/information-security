/**
 * Description : Caesar cipher algorithm
 * Author : Anupam Saikia (GAU-C-17/064)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Function to encrypt plaintext using Caesar cipher.
 * Returns the ciphertext
 */
char *caesarEncrypt(char *plainText, int key)
{
    size_t size = strlen(plainText);
    char *cipherText = (char *)malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
    {
        // Uppercase will remain Uppercase; 'A'=65 'Z'=90
        if (plainText[i] >= 65 && plainText[i] <= 90)
            cipherText[i] = ((plainText[i] + key - 65) % 26) + 65;

        // Lowercase will remain lowercase; 'a'=97 'z'=122
        else if (plainText[i] >= 97 && plainText[i] <= 122)
            cipherText[i] = ((plainText[i] + key - 97) % 26) + 97;

        // Other characters will not change
        else
            cipherText[i] = plainText[i];
    }
    return cipherText;
}

/**
 * Function to decrypt ciphertext using Caesar cipher
 * Returns the plaintext
 */
char *caesarDecrypt(char *cipherText, int key)
{
    key = key % 26; // to make key value between [0-25]
    key = 26 - key;
    return caesarEncrypt(cipherText, key);
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
    char str[100], option = '0';
    int key = 1;
    printf("1. Encrypt\n2. Decrypt using key\n3. Decrypt using bruteforce\nEnter option [1-3] : ");
    scanf("%c", &option);

    switch (option)
    {
    case '1':
        printf("Enter plaintext : ");
        clearBuffer();
        fgets(str, 100, stdin);
        printf("Enter key : ");
        scanf("%d", &key);
        printf("Ciphertext : %s", caesarEncrypt(str, key));
        break;
    case '2':
        printf("Enter ciphertext : ");
        clearBuffer();
        fgets(str, 100, stdin);
        printf("Enter key : ");
        scanf("%d", &key);
        printf("Plaintext : %s", caesarDecrypt(str, key));
        break;
    case '3':
        printf("Enter ciphertext : ");
        clearBuffer();
        fgets(str, 100, stdin);
        for (int i = 0; i < 26; i++)
            printf("Using key = %d : %s", i, caesarDecrypt(str, i));
        break;
    default:
        printf("Enter correct option\n");
        break;
    }

    return 0;
}
