#include<stdio.h>
#include <string.h>
#include <stdbool.h>

//take a pointer to the array as input, and find whether it is a palindrome.
bool isPalindrome(char *input){
    char *forwards;
    char *reverse;
    forwards=input;
    //traverse through the array from each end, comparing character by character.
    reverse=(forwards+strlen(input)-1);
    for(forwards; reverse>=forwards;){
        if(*reverse==*forwards){
            reverse--;
            forwards++;
        }
        else break;
    }
    return(forwards>reverse);
}

//take input from the user, call the isPalindrome function, and print the result to console.
int main(){
    char input[100];
    printf("Enter a message to see if it is a palindrome: ");
    scanf("%s", input);
    if(isPalindrome(input)){
        printf("The message is a palindrome.");
    }
    else printf("The message is not a palindrome.");
    return 0;
}
