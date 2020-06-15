#include <stdio.h>
#include <cs50.h>


int get_GreaterThanOne_value(string prompt);

int main(void)
{
    int n = get_GreaterThanOne_value("Please enter a number: ");
    for(int i= 0; i < n; i++){
        for(int j =0; j< n-i-1;  j++){
            printf(" ");   
        }
       for(int k = 0; k < i+1; k++){
           printf("#");
       }
       printf("  ");
       for(int l = 0; l < i+1; l++){
           printf("#");
       }
       printf("\n");
   }
}
    
    
    
    
    
int get_GreaterThanOne_value(string prompt)
{
    int num;
    do 
    {
        num = get_int("%s",prompt);
    }
    while(num<1 || num>8);
    return num;
}






/*for(int i = 1; i <= n; i++){
        for(int j = 0;j<1;j++){
            for(int k=0; k < i; k++){
                printf("#");
            }
            printf("  ");
            for(int l=0; l<i; l++){
                printf("#");
            }
        }
        printf("\n");
    }

}*/
