#include<stdio.h>
int main(){
char number[13];
char outputnumber[12];
printf("Enter phone number [(999)999-9999]:]");
scanf("%s", number);
int i;
for (i = 1; i < 13; i++){
	if (i == 4){
		outputnumber[i-1] = '-';
	}
	else {outputnumber[i-1] = number[i];}
}
outputnumber[i-1] = '\0'; //signify the end of the string
printf("You entered %s\n", outputnumber);
return 0;
}

