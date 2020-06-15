#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void calculating_index (int letters, int words, int sentences);


int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    /*Instead of compiling the method within the main method, do it within a new function.
    This will allow the variables within the index function to work.
    The calling to the main function is a hassle and won't work too often. */
    calculating_index (letters, words, sentences);
    
}

int count_letters(string text)
{
    int x = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            x++;
        }
    }
    return x;
}

int count_words(string text)
{
    int y = 1;
    for (int j = 0, n = strlen(text); j < n; j++)
    {
        if (isblank(text[j]) == false && isblank(text[j + 1]) == true)
        {
            y++;
        }
    }
    return y;
}

int count_sentences(string text)
{
    int z = 0;
    for (int k = 0, n = strlen(text); k < n; k++)
    {
        if ((text[k]) == 33 || (text[k]) == 46 || (text[k]) == 63)
        {
            z++;
        }
    }
    return z;
}

void calculating_index (int letters, int words, int sentences)
{
    int index = 0;
    float L = (float) letters / (0.01 * words);
    float S = (float) sentences / (0.01 * words);
    index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
       printf("Grade 16+\n");

    }
    else
    {
        printf("Grade %d\n", index);
    }
}