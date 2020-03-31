#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void encrypt(string plainText, string key);
int index_of(char c, bool isUpper);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc == 2)
    {
        bool valid = true;
        string errorCode = "";

        //Check if the key is long enough
        if (strlen(key) != 26)
        {
            errorCode = "Key must contain 26 characters\n";
            printf("%s", errorCode);
            return 1;
        }
        for (int i = 0; i < strlen(key); i++)
        {
            int letterCount = 0;

            //Checking whether or not character is alpha
            if (!isalpha(key[i]))
            {
                errorCode = "Non-alpha character(s) detected\n";
                valid = false;
            }

            //Secondary loop to check how many occurences of the same letter are in the key. If anything other than one, key is invalid.
            for (int j = 0; j < strlen(key); j++)
            {
                if (key[i] == key[j])
                {
                    letterCount++;
                }
            }
            if (letterCount != 1)
            {
                errorCode = "Each letter must be unique\n";
                valid = false;
            }
        }
        if (valid)
        {
            string plainText = get_string("plaintext: ");
            encrypt(plainText, key);
            return 0;
        }
        else
        {
            printf("%s", errorCode);
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

void encrypt(string plainText, string key)
{
    printf("ciphertext:");
    //iterate through the plain text and retrieve corresponding index for each character iteration. Use that to grab the character from the key.
    for (int i = 0; i < strlen(plainText); i++)
    {
        if (isalpha(plainText[i]))
        {
            bool isUpper = isupper(plainText[i]);
            int index = index_of(plainText[i], isUpper);
            
            //converting all keys to lower
            char encryptedChar = tolower(key[index]);
            if (isUpper)
            {
                encryptedChar -= 32;
            }
            printf("%c", encryptedChar);
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}

int index_of(char c, bool isUpper)
{
    int index = 0;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    if (isUpper)
    {
        c += 32;
    }
    for (int i = 0; i < strlen(alphabet); i++)
    {
        if (alphabet[i] == c)
        {
            index = i;
        }
    }
    //printf("index:%i\n", index);
    return index;
}
