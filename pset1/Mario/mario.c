#include<cs50.h>
#include<stdio.h>
void half_pyramid(int n);

int main(void){
    int height;
    do{
        height = get_int("Height: ");
    }while(height<=0||height>23);
    half_pyramid(height);
}
void half_pyramid(int n)
   {
    int spaces;     
    int dashes;
    for(int i = 0; i<n;i++){
        for(spaces = (0); spaces<n-i-1;spaces++){
            printf(" ");
        }
        for (dashes = 0; dashes < i+1; dashes++){
            printf("#");
        }
        printf("\n");
    }
}
