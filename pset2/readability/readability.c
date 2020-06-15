#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    /*Declaring variables from the beginning. All should start at 0.
    The word checker checks for the number of spaces. As such, this, exclusively, start at 1.*/
    string text = get_string("Text: ");
    int count_letters = 0;
    int count_words = 1;
    int count_sentences = 0;

    //This for loop will check for the length of the string, including spaces, punctuation and the like.
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //This if statement will check for the number of letters, done by isalpha command.
        if (isalpha(text[i]))
        {
            count_letters++;
        }

        //This if statement will check for the number of words based on the assumption that no two spaces will come.
        if (isblank(text[i]) == false && isblank(text[i + 1]) == true)
        {
            count_words++;
        }

        //This if statement check for . and ! and ?, the three exclusive ending sequences for sentences.
        if ((text[i]) == 33 || (text[i]) == 46 || (text[i]) == 63)
        {
            count_sentences++;
        }

    }

    //These are the several options needed to calculate the index value.
    int index = 0;
    float L = count_letters / (0.01 * count_words);
    float S = count_sentences / (0.01 * count_words);
    index = round(0.0588 * L - 0.296 * S - 15.8);

    //These several if-statements are used to determine the grade level of the student.
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
        printf("Grade %i\n", index);
    }
}