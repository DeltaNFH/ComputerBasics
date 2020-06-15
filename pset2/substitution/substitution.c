#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    /*This if statement will check for the whether the user put in an input or too many inputs.
    Less than 1 will mean the user didn't type in anything.
    Greater than 2 will mean the user typed in more than the expected cipher code.*/
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    /*This loop 
    */
    for (int h = 0; h < strlen(argv[1]); h++)
    {
        if (!(isalpha(argv[1][h])))
        {
            printf("Key must contain only alphabetical characters.\n");
            return 1;
        }
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must be 26 letters long.\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        int j = 0;
        for (int k = 0; k < strlen(argv[1]); k++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][k]))
            {
                j++;
            }

            if (j == 2)
            {
                printf("Repeated characters.\n");
                return 1;
            }
        }
    }

    char cipher[2][26];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        cipher[0][i] = 65 + i;
        cipher[1][i] = argv[1][i];
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                for (int j = 0; j < strlen(argv[1]); j++)
                {
                    if (tolower(cipher[0][j]) == plaintext[i])
                    {
                        printf("%c", tolower(cipher[1][j]));
                    }
                }
            }
            if (isupper(plaintext[i]))
            {
                for (int j = 0; j < strlen(argv[1]); j++)
                {
                    if (toupper(cipher[0][j]) == plaintext[i])
                    {
                        printf("%c", toupper(cipher[1][j]));
                    }
                }
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}