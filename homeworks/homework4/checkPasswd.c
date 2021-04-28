#include <stdio.h>
#include <string.h>

int main(){
    //Take a character array input from the command line.
    char input[10];
    printf("Enter a password to check: " );
    scanf("%s", input);
    int length;
    //find the length of the input
    length=strlen(input);
    int pointslost;

    //if the length of the input is less than 10, then add 5 points lost for each missing character.
    if(length<10){
        pointslost=((10-length)*5);
	//if more than 30 points were lost, the password is unsafe.
        if(pointslost>30){
            printf("The password is unsafe! Please reset. It lost this many points: %d",pointslost);
        }
	else printf("The password is safe.");
    }
    else printf("The password is safe.");
    return 0;
}
