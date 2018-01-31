#include <stdio.h>

long f(long n)
{
	if(1==n)
		return 1;
	else
		return n*f(n-1);
}
int main(void)
{
	int n;
	while(1)
	{
		printf("please input a num:");
		scanf("%d",&n);
		printf("result is:");
		printf("%ld",f(n));
		printf("\n\n");
	 } 
	return 0;
 } 
