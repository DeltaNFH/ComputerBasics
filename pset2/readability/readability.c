#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int* numOfAll(string x);
double averageLetters(double totalLetters, double totalWords);
double averageSentences(double totalWords, double totalSentences);
void colemanLiauIndex(double L, double S);

int main(void)
{
    string text = get_string("Text: ");
    int* textInfo = numOfAll(text); //a letter is any lowercase character from a to z or any uppercase character from A to Z

    double averageNumOfLetters = averageLetters(textInfo[0], textInfo[1]);
    double averageNumOfSentences = averageSentences(textInfo[1] ,textInfo[2]);
    colemanLiauIndex(averageNumOfLetters, averageNumOfSentences);

    //int numOfWords = words(text);//any sequence of characters separated by spaces should count as a word
    //int numOfSentences = sentences(text);//occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
    //index = 0.0588 * L - 0.296 * S - 15.8
    //Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

}

int* numOfAll(string x){
    int letters = 0, words = 1, sentences = 0;
    int n = strlen(x);
    static int info[3];
    for(int i = 0; i < n; i++){
        if(x[i] >= 'a' && x[i] <= 'z'){
            letters++;
        }
        else if(x[i] >= 'A' && x[i] <= 'Z'){
            letters++;
        }
        else if(x[i] == ' '){
            words++;
        }
        else if(x[i] == '.' || x[i] == '!' || x[i] == '?'){
            sentences++;
        }
    }
    info[0] = letters;
    info[1] = words;
    info[2] = sentences;
    return info;
}

double averageLetters(double totalLetters, double totalWords){ //average number of letters per 100 words
    return ((totalLetters*100)/totalWords);
}

double averageSentences(double totalWords, double totalSentences){//average number of sentences per 100 words
     return ((totalSentences*100)/totalWords);
}

void colemanLiauIndex(double L, double S){
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    if(grade <= 16 && grade>=1){
        printf("Grade %i\n", grade);
    }
    else if(grade < 1){
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade 16+\n");
    }
}


/*int numOfWords(string x){
    int count = 0;
    int n = strlen(x);
    for(int i = 0; i < n; i++ ){
        if(x[i] == ' '){
            count++;
        }
    }


}

int numOfSentences(string x){


}*/