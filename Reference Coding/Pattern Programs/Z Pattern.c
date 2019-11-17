//***************************************************************//
#include <stdio.h>

int main(void) {
	// your code goes here
	int m, n;
	printf("---------------\n");
	printf("Enter dimensions...\n");
	scanf("%d %d",&m,&n);
	printf("Dimensions are: %d x %d\n", m,n);
	
	for (int i=1; i<=m ; ++i)
	{
		for (int j=1;j<=n;++j)
		{
			if (i == 1 || i == m || j == n-i+1)
				printf("*  ");
			else
				printf("   ");
		}
		printf("\n");
	}
	return 0;
}
//***************************************************************//