#include <stdio.h>

unsigned int factorial (unsigned int n){
	if (n == 0)
		return 1;
	else return n * factorial(n-1);
}
int main (){
	int input;
	printf("Enter a positive integer to compute the factorial of: ");
	scanf("%d", &input);
	int result;
	result = factorial(input);
	printf("%d\n", result);
	return 0;
}
