#include<stdio.h>
#include<stdlib.h>
int front=-1;
int rear=-1;
int n;
void enqueue(int a[],int  x){
	if(rear==n-1){
		printf("queue is full \n");
	}
	else
	{
		if(front ==-1)
		{
			front==0;
		}
		rear++;
		a[rear]=x;
		printf("element %d is inserted \n",x);
	}
}
void dequeue(int a[])
{
	if(rear==-1 || front>rear)
	{
		printf("Queue underflow \n");
	}
	else
	{
		printf("The element %d is Deleted \n",a[front]);
		front++;
	}
}
void display(int a[])
{
	if (rear ==-1 ||front>rear)
	{
		printf("The queue is underflow \n");
	}
	else
	{
		printf("The elements are \n");
		for(int i=front;i<=rear;i++){
			printf("%d \t",a[i]);
		}
	}
}
void main()
{
	printf("Enter the size of an queue\n");
	scanf("%d",&n);
	int a[n],e;
	while(1)
	{
		int ch;
		printf("1.Enqueue \n");
		printf("2.Dequeue\n");
		printf("3.Display \n");
		printf("4.Exit\n");
		printf("enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element to be inserted \n");
				scanf("%d",&e);
				enqueue(a,e);
				break;
			case 2:dequeue(a);
				break;
			case 3:display(a);
				break;
			case 4:exit(0);
			default:printf("Enter the correct choice:");
				break;
		}
	}
}
