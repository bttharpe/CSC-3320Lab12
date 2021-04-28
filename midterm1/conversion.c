#include <stdio.h>
#include <math.h>

long decToBin(int decimalinput){
	int remainder;
	long binary = 0;
	int i;
	i = 1;
	while (decimalinput != 0){
		remainder = decimalinput % 2;
		decimalinput = decimalinput / 2;
		binary = binary + remainder*i;
		int temp;
		binary = binary + temp;
		i = i * 10;
	}
	return binary;		
}

int binToDec(long binaryinput){
	int remainder;
	long decimal = 0;
	int i;
	i = 0;
	while (binaryinput!=0){
		remainder = binaryinput % 10;
		binaryinput = binaryinput / 10;
		decimal = decimal + remainder*pow(2,i);
		i++;
	}
	return decimal;
}

int main(){
        int input;
        printf("Would you like to convert (1) Integer to Binary or (2) Binary to Integer?");
        scanf("%d", &input);
        if (input == 1){
                int decimalinput;
                printf("Please enter an integer: ");
                scanf("%d", &decimalinput);
                printf("%ld\n", decToBin(decimalinput));
        }
        else{
                long binaryinput;
                printf("Please enter a binary number: ");
                scanf("%ld", &binaryinput);
                printf("%d\n", binToDec(binaryinput));
        }
	return 0;
}
