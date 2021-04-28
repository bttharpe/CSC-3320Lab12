#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//takes a pointer to an array as input and checks to see if it is missing a lower case character
bool missingLower(char input[]){
    int i;
    for (i=0; i<strlen(input); i++){
        if(islower(input[i])){
            return false;
        }
    }
    return true;
}

//takes a pointer to an array as input and checks to see if it is missing an upper case character
bool missingUpper(char input[]){
    int i;
    for (i=0; i<strlen(input); i++){
        if(isupper(input[i])){
            return false;
        }
    }
    return true;
}

//takes a pointer to an array as input and checks to see if it is missing a digit as a character
bool missingDigit(char input[]){
    int i;
    bool founddigit=false;
    for (i=0; i<strlen(input); i++){
        if((isdigit(input[i]))){
            founddigit=true;
        }
    }
    return (!founddigit);
}

//takes a pointer to an array as input and checks to see if it has more than two consecutive characters of the same type (i.e. 2 or more digits or 2 or more letters in a row)
bool consecutive(char input[]){
    int i;
    for (i = 0; i<strlen(input)-2; i++){
        if((isalpha(input[i]) && (isalpha(input[i+1]) && (isalpha(input[i+2])) || (isdigit(input[i]) && isdigit(input[i+1]) && isdigit(input[i+2]))))){
            return true;
        }
    }
    return false;
}

int main(){
    //take a character array as input
    char input[10];
    printf("Enter a password to check: " );
    scanf("%s", input);
    int length;
    //calculate the lenght of the input
    length=strlen(input);
    int pointslost=0;
    //run each function individually and tally up the points lost
    if(missingLower(input)){
        pointslost=pointslost+20;
    }
    if(missingUpper(input)){
        pointslost=pointslost+20;
    }
    if(missingDigit(input)){
        pointslost=pointslost+20;
    }
    if(consecutive(input)){
        pointslost=pointslost+20;
    }
    if(length<10){
        pointslost=pointslost+((10-length)*5);
    }
    //tell the user whether or not the password is safe and the total number of points lost
    if(pointslost>30){
        printf("The password is unsafe and it lost this many points: %d", pointslost);
    }
    else printf("The password is safe but it lost this many points: %d", pointslost);
    return 0;
}
