#include <stdio.h>

//This function takes 2 double pointers as input, and swaps their values by using a temp variable.
void swap(double *first, double *second){
    double temp = *first;
    *first = *second;
    *second = temp;
}

//This function takes a character, a pointer to a double array, and int as input.
void sort_numeric(char input, double *arr, int length){
    //If the user inputs some form of 'a', use selection sort to sort in ascending order.
    if((input == 'a') || (input == 'A')){
        int i;
        int j;
        int smallest;
        for(i = 0; i < length-1; i++){
            smallest = i;
            for(j = i+1; j < length; j++){
                if(arr[j] < arr[smallest]){
                    smallest = j;
                }
            }
            //Call the swap function on the addresses of these array values.
            swap(&arr[smallest], &arr[i]);
        }
    }
    //If the user inputs some form of 'b', use selection sort to sort in descending order.
    else if((input == 'b') || (input == 'B')){
        int i;
        int j;
        int largest;
        for(i = 0; i < length-1; i++){
            largest = i;
            for(j = i+1; j < length; j++){
                if(arr[j] > arr[largest]){
                    largest = j;
                }
            }
            //Call the swap function on the addresses of these array values.
            swap(&arr[largest], &arr[i]);
        }
    }
    //Otherwise, the user input is invalid.
    else printf("Unrecognized input");
    
    int k;
    //Iterate through the array and print the properly formatted version of each value.
    for(k = 0; k < length; k++){
        printf("%g, ", arr[k]);
    }
}

int main(){
    double arr[] = {10, 0.25, -2342, 12123, 3.145435, 6, 5, 5.999, -2, -5, -109.56};
    printf("Enter A or a for ascending order sort, or B or b for descending order sort:  ");
    //Scan a character input from the user.
    char input;
    scanf("%c", &input);
    //Compute the lenght of the double array 'arr'.
    int length = sizeof(arr)/sizeof(arr[0]);
    //Pass the input character, a reference to the double array, and the length of the double array to the sort function.
    sort_numeric(input, arr, length);
}


