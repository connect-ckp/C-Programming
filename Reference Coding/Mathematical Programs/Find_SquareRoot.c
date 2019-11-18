#include <stdio.h>

float absoluteValue(float num);
float squareRoot(float num);

int main(void)
{
	float num, sqrt;
	
	printf("Enter a positive number to find square root of...\n");
	scanf("%f", &num);
	
	sqrt = squareRoot(num);
	printf("Square root of %.2f is %.2f\n", num, sqrt);	
}

float squareRoot(float sqrtNum)
{
	const float epsilon = 0.00001;
	float guess = 1.0;
	float returnValue = 0.0;
	
	if(sqrtNum < 0)
	{
		printf("Negative number provided.\n");
		returnValue = -1.0;
	}
	else
	{
		while(absoluteValue(guess*guess - sqrtNum) >= epsilon)
		{
			guess = (sqrtNum/guess + guess) / 2.0;
		}
		
		returnValue = guess;
	}
	
	return returnValue;	
}

float absoluteValue(float absNum)
{
	if(absNum < 0)
		absNum*=(-1);
	
	return absNum;
}
