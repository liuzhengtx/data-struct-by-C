/*
	Name: 
	Copyright: 
	Author: 
	Date: 31/01/18 10:18
	Description: 1、1、2、3、5、8、13、21、´´
*/
#include <stdio.h>
int f(int n)
{
	if(0==n|1==n)
	{
		return 1;
	}
		else
		{
			return (f(n-1)+f(n-2));
		}
		
}

int main(void)
{
	int n;
	while(1)
	{
		printf("please input a num:");
		scanf("%d",&n);
//		f(n);
		printf("%d ",f(n));
		printf("\n");
	}
	return 0;
 } 
