#include<stdio.h>
void toh(int n,char a,char b,char c)
{
	if (n==1)
	{
		printf("\n moce disk %d from rod %c to rod%c",n,a,b);
		return;
	}
	toh(n-1,a,c,b);
	printf("\n Move disk from %d from rod%c to rod%c",n,a,b);
	toh(n-1,c,b,a);
}
void main()
{
	int n;
	printf("\n enter no.");
	scanf("%d",&n);
	toh(n,'a','c','b');
}
