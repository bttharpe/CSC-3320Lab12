#include <stdio.h>
#include <ctype.h>

int main(){
	char inputfile[20];
	printf("Please enter a txt file name in the form file.txt ");
	scanf("%s",inputfile);
	int i;
	int mostcommon = 0;
	int arr[256]={0};
	int character;

	FILE * file;
	file = fopen(inputfile, "r");
	if(!file){
		printf("Cannot open file");
		return 0;
	}
	
	while((character = fgetc(file)) != EOF){
		arr[character]++;
	}
	
	for(i=1; i<256; i++){
		if((arr[i] > arr[mostcommon]) && (isalpha((char)i) != 0)){
			mostcommon = i;
		}
	}
	
	/*calculate the final number of occurences of the most common character
 * by adding the counts of it's upper and lower case counterparts*/
	int finalvalue = arr[mostcommon] + arr[mostcommon-32];	
	printf("The most frequent letter is %c. ", (char)mostcommon);
	printf("It appeared %d times.", finalvalue);
	return 0;
}
	
