#include<stdio.h>
#include<stdlib.h>
int top = -1,n;
void push(int a[],int e)
{
if (top=n-1)
{
	printf("stack is full");
}
else
	{
	top++;
	a[top]=e;
	printf("******************************** \n");
	printf("element to be pushed",e);
	printf("********************************");
	}
}
void pop(int a[])
{
	if(top==-1)
	{
		printf("\n********************\n");
		printf("stack is underflow");
	}
	else
	{
		printf("element popped \n",a[top--]);
	}
}
void peep(int a[])
{
	if(top==-1)
	{
		printf("Stack is underflow \n");
	}
	else
	{
		printf("Element is peeped \n",a,top[]);
	}
}
void display(int a[])
	{
	if(top==-1)
	{
		printf("Stack is empty");
	}

