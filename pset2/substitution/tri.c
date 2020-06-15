#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

boold valid_triangle(int a, int b, int c);

int main (void)
{
    int a, b, c;
    a = 3;
    b = 3;
    c = 3;
    
    bool works = valid_triangle(a, b, c);
    
    printf("Valid %b\n", works);
}

bool valid_triangle(int a, int b, int c)
{
    bool valid = false;
    if (a )
}