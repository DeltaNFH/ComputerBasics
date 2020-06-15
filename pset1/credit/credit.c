#include <stdio.h>
#include <cs50.h>

/*American Express uses 15-digit numbers,
MasterCard uses 16-digit numbers, and
Visa uses 13- and 16-digit numbers.*/

int length_checker(long long ccnumber);
//bool checksum (long long ccnumber);

int main(void)
{
    long long ccnumber;

    do
    {
        ccnumber = get_long_long("Enter your credit card number: ");
    }
    while (ccnumber < 0);

    printf("%lli\n", ccnumber);

    int x = length_checker(ccnumber);

   //checksum (ccnumber);

}

int length_checker(long long ccnumber)
{
    long long n = ccnumber;
    int count = 0;
    do
    {
        n /= 10;
        count++;
    }
    while (n != 0);
    return count;
}

/*bool checksum (long long ccnumber)
{
     Using modulus, we can find the remainder of the ccnumber.
    By doing so, we are able to find the last digit of the number.
    Recall that the 2nd to last number is going through the * 2 calc.
    So do a for loop.
    1st modulus will give remainder  based on the value of i.
    set i = 1
    if i is odd, then add to added_sum.
    if i is even, times by 2 then add to product_sum
    continue till i = length_checker (ccnumber).
        fix later of length_checker to include in while loop && bool method.


}*/