#include<stdio.h>
#include<stdlib.h>
int front =-1;
int rear =-1;
int n;
void Enqueue(int a[],int x)
{
	if(((rear+1)%n)== front)
	{
		printf("Queue is full");
	}
	else
	{
		if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
			a[rear]=x;
		}
		else
		{
			rear=(rear+1)%n;
			a[rear]=x;
		}
		printf("The element %d is Inserted \n",x);
	}
}
void Dequeue(int a[])
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is underflow");
	}
	else
	{
		printf("the element %d is Deleted \n",a[front]);
	 	if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=((front+1)%n);
		}
	}
}
void Display(int a[])
{
	if(front==-1 && rear==-1)
	{
		printf("queue is underflow \n");
	}
	else
	{
		if(front==rear)
		{
			printf("The Element is %d\n",a[front]);
		}
		else
		{
		int i = front;
		printf("the Elements are \n");
		while(i!= rear)
		{
			printf("%d \t",a[i] );
			i = ((i+1)%n);
		}
		printf("%d\t", a[rear] );
		}
	}
}
void main()
{
	printf("Enter the size of the Queue \n");
	scanf("%d", &n);
	int a[n],e;
	while(1)
	{
		int ch;
		printf("\n1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be inserted \n");
				scanf("%d", &e);
				Enqueue(a,e);
				break;
			case 2:
				Dequeue(a);
				break;
			case 3:
				Display(a);
				break;
			case 4:exit(0);
			default: printf("Enter the choice Correctly");
			break;
		}
	}
}
