#include <stdio.h>
#include <string.h>
#include <ctype.h>

//this function takes 2 char pointers and an integer index as parameters, then performs ascii value calculations to swap their values without a tertiary variable.
void swap(char *first, char *second, int i){
	first[i]=(char*)((int)first[i] + (int)second[i]);
	second[i]=(char*)((int)first[i] - (int)second[i]);
	first[i]=(char*)((int)first[i] - (int)second[i]);
}

//this function takes user input, calls the swap function, and outputs the result.
int main(){
	char input[50];
	char input2[50];
	printf("Enter the first sentence: ");
	fgets(input, 50, stdin);
	printf("Enter the second sentence: ");
	fgets(input2, 50, stdin);
	int i;
	int length = strlen(input);
//traverse through the length of the first char array
	for(i=0; i<length; i++){
//if the types of characters at each index position in each array every differs, call the swap function for that index.
		if((isdigit(input[i])&&(isalpha(input2[i]))) || (isalpha(input[i])&&(isdigit(input2[i])))){
			swap(input, input2, i);
		}
//otherwise, replace each with a blank character if they are of the same type.
		else{
			input[i]=' ';
			input2[i]=' ';
		}
	}
	printf("Result 1: %s \n", input);
	printf("Result 2: %s \n", input2);
	return 0;
}
		
