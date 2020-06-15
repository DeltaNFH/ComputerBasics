#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool checkint(string text);
int stringToInt(string text);
bool uppercase(char character);
bool lowercase(char character);


int main(int argc, string argv[])
{
    // Wrong arguments
    if (argc != 2 || !checkint(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Correct arguments
    else 
    {
        // Take string from user
        string plain = get_string("plaintext: ");
        
        // Use stringToInt function to get key
        int key = stringToInt(argv[1]) % 26;
        
        // Start loop in shifting and printing EACH character one by one
        int charint = 0;
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plain); i++)
        {
            // If lowercase or uppercase alphabet
            if (uppercase(plain[i]) || lowercase(plain[i]))
            {
                charint = plain[i] + key;
                if ((charint > 90 && uppercase(plain[i])) || (charint > 122 && lowercase(plain[i])))
                {
                    charint -= 26;
                }
                printf("%c", charint);
            }
            else
            {
                printf("%c", plain[i]);
            }
        }
        printf("\n");
    }
}

// Checks if command-line argument is an int
bool checkint(string text)
{
    bool integer = true;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] < 48 || text[i] > 57)
        {
            integer = false;
        }
    }
    return integer;
}

// Converts string to integer
int stringToInt(string text)
{
    int nums[10];
    int number = 0;
    int b;
    for (int k = 0; text[k] != '\0'; k++)
    {
        b = k;
    }
    for (int i = 0; i <= b; i++)
    {
        nums[i] = text[i];
        if (nums[i] >= 48 && nums[i] <= 57)
        {
            nums[i] = nums[i] - 48;
            for (int j = b - i; j > 0; j--)
            {
                nums[i] *= 10;
            }
            number += nums[i];
        }
    }
    return number;
}

bool lowercase(char character)
{
    if (character <= 122 && character >= 97)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool uppercase(char character)
{
    if (character <= 90 && character >= 65)
    {
        return true;
    }
    else
    {
        return false;
    }
}