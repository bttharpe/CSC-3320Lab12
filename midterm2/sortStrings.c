#include <stdio.h>
#include <string.h>

//This function does a simple bubble sort on the input array of strings.
void sort_alphabetic(char input, char arr[8][15], int length){
    int i, j, smallest;
    char temp[15];
    //If the user inputs some form of 'a' then do ascending alphabetical sort.
    if((input == 'a') || (input == "A")){
        for(i = 0; i < length; i++){
            for(j = i+1; j < length; j++){
                if(strcmp(arr[i],arr[j]) > 0){
                    strcpy(temp, arr[i]);
                    strcpy(arr[i], arr[j]);
                    strcpy(arr[j], temp);
                }
            }
        }
    }
    //If the user inputs some form of 'd', then do descending alphabetical sort.
    else if ((input == 'd') || input == "D"){
        for(i = 0; i < length; i++){
            for(j = i+1; j < length; j++){
                if(strcmp(arr[i],arr[j]) < 0){
                    strcpy(temp, arr[i]);
                    strcpy(arr[i], arr[j]);
                    strcpy(arr[j], temp);
                }
            }
        }
    }
    //Otherwise, ouput an error message.
    else printf("Unrecognized input.");
    int k;
    //Go through and print each element of the resulting array.
    for(k = 0; k < length; k++){
        printf("%s, ", arr[k]);
    }
}

int main(){
    //Declare and initialize the array of strings.
    char arr[8][15] = {"Systems", "Programming", "Deep", "Learning", "Internet", "Things", "Robotics", "Course"};
    printf("Enter A or a for alphabetical sort, or D or d for reverse alphabetical sort: ");
    char input;
    //Scan user input to see which way they want it sorted.
    scanf("%c", &input);
    //Call the sort function with user input, the array, and the set length of the array.
    sort_alphabetic(input, arr, 8);
}


