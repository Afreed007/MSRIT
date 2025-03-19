#include<stdio.h>
#include<stdlib.h>
int front =-1;
int rear = -1;
int n;
void Enqueue(int a[], int x)
{
	if(rear == n-1)
	{
		printf("Queue is Full \n");
	}
	else
	{
		if(front==-1)
		{
			front = 0;
		}
		rear++;
		a[rear] = x;
		printf("Element %d is inserted \n", x);
	}
}
void Dequeue(int a[])
{
	if(rear == -1 || front >rear)
	{
		printf("The queue is Underflow \n");
		front = rear = -1;	
	}
	else
	{
		printf("The Element %d is Deleted \n", a[front]);
		front++;
		n++;
	}

}
void Display(int a[])
{
	if(rear == -1 || front > rear)
	{
		printf("The queue is Underflow \n");
		
	}
	else
	{
		printf("The elements are \n");
		for(int i = front; i<=rear; i++)
		{
			printf("%d \t ", a[i]);
		}
	}
}
void main()
{
	printf("Enter the size of the Queue \n");
	scanf("%d", &n);
	int a[n],  e;
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
			
			case 4:
				exit(0);
				
			default: printf("Enter the choice Correctly");
			break;
		}	
	}
}
