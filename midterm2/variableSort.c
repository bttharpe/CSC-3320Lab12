#include <stdio.h>
#include <stdlib.h>

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
        for(i = 0; i < length; i++){
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
        printf("%g ", arr[k]);
    }
}

int main(){
    int num;
    double *arr;
    int i;
    int sum;
    printf("Enter A or a for ascending order sort, or B or b for descending order sort: ");
    //Scan a character input from the user.
    char input;
    scanf(" %c", &input);
    //Scan the size of the array from the user.
    printf("Enter the number of array elements: ");
    scanf("%d", &num);
    //Dynamically allocate an array based on user input.
    arr = (int *) malloc(num * sizeof(double));
    printf("\nNow enter the elements of the double array, pressing enter after each entry. After your last entry, enter 'done' with no decimal point.\n");
    
    for(i = 0; i < num; i++){
        scanf("%lf ", (arr + i));
        sum = sum + *(arr + i);
    }
    
    //Pass the input character, a reference to the double array, and the length of the double array to the sort function.
    sort_numeric(input, arr, num);
    free(arr);
}


