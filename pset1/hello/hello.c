#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /*Code asks for name, returns name with "Hello so-and-so.
                                             This is cs50!" */
    string name = get_string("What is your name?\n");
    printf("Hello, %s.\nThis is cs50!\n", name);
}