#include <stdio.h>
#include <cs50.h>

//American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers.
//All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 
//(they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. 

long long checkLength(long long number);
void checkVisa(long long number);
void checkAmex(long long number);
void checkMasterCard(long long number);
bool checkValuability(long long number);
long long get_longAndNumber(string prompt);

int main(void)
{


    long long creditNumber;
    bool checker;
    creditNumber = get_long_long("Please enter you credit card number:\n");
    long long numb = creditNumber;

    if(checkLength(creditNumber) == 13){
        checkVisa(creditNumber);
    }
    else if(checkLength(creditNumber) == 15){
        checkAmex(creditNumber);
    }
    else if(checkLength(creditNumber) == 16){
        for(int i = 0; i < 15; i++){
            numb = numb/10;
        }
        if(numb == 4){
            checkVisa(creditNumber);
        }
        else{
            checkMasterCard(creditNumber);
        }
    }
    else{
        printf("INVALID\n");
    }
}


long long checkLength(long long number){
    long long count=0;
    while(number!= 0)
    {
        number /= 10;
        count++;
    }
    return count;
}



void checkVisa(long long number){
    bool checker = checkValuability(number);
    if(checker == true){
        printf("VISA\n");
    }
    else{
        printf("INVALID\n");
    }
}

void checkAmex(long long number){
    long long value = number;
    for(int i = 0; i < 13; i++){
        value /= 10;
    }
    if(value == 34 || value == 37){
        printf("AMEX\n");
    }
    else{
        printf("INVALID\n");
     }
}

void checkMasterCard(long long number){
    long long value = number;
    for(int i = 0; i < 14; i++){
        value /= 10;
    }
    if(value == 51 || value == 52 || value == 53 || value == 54|| value == 55){
        bool checker = checkValuability(number);
        if(checker == true){
            printf("MASTERCARD\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    else{
        printf("INVALID\n");
    }
}

bool checkValuability(long long number){
    long long num;
    long long num2;
    long long storage =0;
    long long storage2=0;
    int length = checkLength(number);
    for(int i = 0; i < elength/2; i++){
        num2 = number%10;
        storage2 = storage2 + num2;
        number /=10;
        num = number%10;
        if(num>4){
           num = num*2;
           storage += (num%10) + (num/10);
        }
        else{
            storage = storage + (num*2);
        }
        number /=10;
    }
    if((storage+storage2)%10 == 0){
        return true;
    }
    else{
        return false;
    }
}


