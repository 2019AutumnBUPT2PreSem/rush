#include <stdio.h>

void markline(int n)
{
	printf("\n");
	for(int i=0;i<=n;i++)
	{ 
	    printf("*");
    }
    
}
void strailine(int n)
{
	printf("\n");
	for(int i=0;i<=n;i++)
	{
		printf("-");
	}
}
void blankline(int n) 
{
	printf("\n");
	for(int i=0;i<=n;i++)
	{
		printf(" ");
	}
}