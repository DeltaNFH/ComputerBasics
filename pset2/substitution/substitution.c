#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//                       8
/*                ABCDEFGHIJKLMNOPQRSTUVWXYZ
   ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
      plaintext:  HELLO
      ciphertext: EHBBQ   */


int main(int argc, string argv[])
{
    if(argc != 2){
        printf("ERROR KEY NEEDED\n");
        return 1;
    }
    if(strlen(argv[1]) != 26){
        printf("ERROR KEY MUST BE 26 LETTERS\n");
        return 1;
    }
    for(int i = 0; i < 26; i++){
        if(!(isalpha(argv[1][i]))){
            printf("INVALID KEY");
            return 1;
        }
    }
    int frequency[26]= {0};
    for(int i = 0; i < 26; i++){
        if(!(isalpha(argv[1][i]))){
            printf("INVALID KEY");
            return 1;
        }
        int index = toupper(argv[1][i])- 'A';
        if(frequency[index] > 0){
            return 1;
        }
        frequency[index]++;
    }


    string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cipherText = "";
    string plainText = get_string("plaintext:\n ");
    //user types: HELLO
    int storage;
    printf("ciphertext: ");
    for(int i = 0; i < strlen(plainText); i++){
        if (plainText[i] >= 'A' && plainText[i] <= 'Z'){
             for(int j = 0; j < strlen(upperCase); j++){
                 if(plainText[i]== upperCase[j]){
                     storage = j;
                 }
             }
             printf("%s%c", cipherText , toupper(argv[1][storage]));
        }
        else if(plainText[i] >= 'a' && plainText[i] <= 'z'){
            for(int k =0; k < strlen(lowerCase); k++){
                if(plainText[i] == lowerCase[k]){
                    storage = k;
                }
            }
            printf("%s%c", cipherText ,tolower(argv[1][storage]));
            //strcat(cipherText, argv[1][storage]);
        }
        else{
            printf("%s%c", cipherText, plainText[i]);
            //strcat(cipherText, plainText[i]);
        }

    }
    printf("\n");
    return 0;


}