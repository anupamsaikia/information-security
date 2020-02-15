#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *caesarEncrypt(char *plainText, int key, int size)
{
    char *cipherText = (char *)malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
    {
        // Uppercase will remain Uppercase
        if (plainText[i] >= 65 && plainText[i] <= 90)
        {
            cipherText[i] = ((plainText[i] + key - 65) % 26) + 65;
        }
        // Lowercase will remain lowercase
        else if (plainText[i] >= 97 && plainText[i] <= 122)
        {
            cipherText[i] = ((plainText[i] + key - 97) % 26) + 97;
        }
        // Other characters will not change
        else
        {
            cipherText[i] = plainText[i];
        }
    }

    return cipherText;
}

char *caesarDecrypt(char *cipherText, int key, int size)
{
    key = key % 26; // to make key value between [0-25]
    key = 26 - key;

    return caesarEncrypt(cipherText, key, size);
}

int main(int argc, char const *argv[])
{
    char *str = "Sample Text?";
    int len = strlen(str);
    int key = 10;

    printf("Text: %s\n", str);
    printf("Encrypted: %s\n", caesarEncrypt(str, key, len));
    printf("Decrypted: %s\n", caesarDecrypt(caesarEncrypt(str, key, len), key, len));

    return 0;
}
