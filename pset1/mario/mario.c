#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    /*do-while loop asks user for an integer between 1 and 8
    All other inputs are rejected and user is asked again. */
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //The outer loop can be said to affect the number of rows in the code.
    for (int i = 0; i < n; i++)
    {
        /*This inner loop will go through if-else statements to check the number of hashtags & spaces.
        The pattern I found was that the number of spaces and hastags sum up to the user input. */
        for (int j = 0; j < n; j++)
        {
            if (i + j >= n - 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        //This will create the two-space gap between the two halves of the pyramid.
        printf("  ");

        /*This for-loop will create the other half of the pyramid.
        As spaces are irrelevant here, we only need to focus on the hastags.
        We can't use the user input to check her as the user input is a constant.
        Comparing this number to i instead will continually change the break condition.
        This is helpful in ensuring that each row has a different number of hastags. */
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

    //Finally, at the end of making a row, the program should create a new row.
    printf("\n");
    }
}