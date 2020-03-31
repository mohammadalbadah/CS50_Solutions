#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool validate_key(string input);
void crypto(int key);

int main(int argc, string argv[])
{
    int key = 0;

    if (argc == 2)
    {
        if (validate_key(argv[1]))
        {
            key = atoi(argv[1]);
            crypto(key);               
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
}

bool validate_key(string input)
{
    bool isValid = true;

    for (int i = 0; i < strlen(input); i++)
    {
        if (!isdigit(input[i]))
        {
            isValid = false;
        }
    }
        
    return isValid;
}

void crypto(int key)
{
    string plainText = get_string("Plain Text: ");
    printf("ciphertext:");
    
    for (int i = 0; i < strlen(plainText); i++)
    {
        int character = plainText[i];
        if (isalnum(character))
        {
            character += key;
            if (islower(plainText[i]))
            {
                //will wrap back to a
                while (122 % character >= 122)
                {
                    character = 96 + (character - 122);
                }
            }
            else if (isupper(plainText[i]))
            {
                //will wrap back to A
                while (90 % character >= 90)
                {
                    character = 64 + (character - 90);
                }
            }
            printf("%c", character);
        }
        else
        {
            printf("%c", character);
        }
    }
    printf("\n");
}
