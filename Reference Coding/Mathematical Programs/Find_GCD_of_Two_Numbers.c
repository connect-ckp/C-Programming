#include <stdio.h>

int main(void) {
	// your code goes here
	int num1, num2;
	int temp;
	printf("Enter Two Numbers to Calculate GCD...\n");
	scanf("%d %d",&num1,&num2);
	
	while(num2 != 0)
	{
		temp = num1 % num2;
		num1 = num2;
		num2 = temp;
	}
	
	printf("GCD is: %d", num1);
	
	return 0;
}