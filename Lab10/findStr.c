#include<stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char smallestword[20];
    char largestword[20];
    int length;
    bool done = false;
    while(!done){
        char input[20];
        printf("Enter word: ");
        scanf("%s", input);
        length = strlen(input);
        if(length==4){
            done = true;
        }
        if(strcmp(input, smallestword)<0){
            strcpy(smallestword, input);
        }
        if(strcmp(input, largestword)>0){
            strcpy(largestword, input);
        }
    }
    printf("Smallest word: %s \n", smallestword);
    printf("Largest word: %s", largestword);
    return 0;
}

