#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
} *new=NULL, *head=NULL, *temp=NULL, *tail=NULL;

//void Create(int a){
//	new = (struct node*) malloc(sizeof(struct node));
//	new->data =a;
//	new-> next = NULL;
//	head = new;
//	temp = new;
//}

void Einsert(int a)
{
	new = (struct node*) malloc(sizeof(struct node));
	new->data = a;
	new->next = NULL;
	if(head == NULL)
	{
		head = new;
		temp = new;
	}
	else
	{
		temp->next = new;
		temp = new;
	}

}

void Binsert(int a)
{
	new = (struct node*) malloc(sizeof(struct node));
	new->data =a;
	new->next=NULL;
	if(head == NULL)
	{
		head=new;
	}
	else
	{
		new->next = head;
		head = new;
	}
}
void Search(int a){
	struct node *ptr;
	int item,i=0,flag;
	ptr = head;
	if(ptr == NULL)
	{
		printf("Empty list");
	}
	else
	{
		printf("Enter item to be searched");
		scanf("%d",&item);
		while(ptr!=NULL)
		{
			if(ptr->data == item)
			{
				printf("Item fond at location %d",i+1);
				flag=0;
				return;
			}
			else
			{
				flag=1;
			}
			i++;
			ptr=ptr->next;
		}
		if(flag==1)
		{
		printf("Item not found");
		}
	}
}

void Bdelete()
{

	struct node *temp;
	temp = head;
	head = head->next;
	temp->next = NULL;
}

void Edelete()
{
		struct node *temp;
		temp = head;
		while(temp->next!=tail)
		{
			temp = temp->next;
		}
		temp->next =NULL;
		tail = temp;
}

void Display()
{
	struct node *temp;
	temp=head;
	if(temp ==NULL)
	{
		printf("Currently list is empty\n");
	}
	else
	{
		while(temp !=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->next;
		}
	}
}


void main()
{
	int a;
	while(1)
	{
		int ch;
		printf("\n1.Insert at end\n");
		printf("\n2.Insert at begining\n");
		printf("\n3.Display\n");
		printf("\n4.Delete at begining\n");
		printf("\n5.Searching\n");
		printf("\n6.Delete at end\n");
		printf("\n7.Exit\n");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be inserted \n");
				scanf("%d", &a);
				Binsert(a);
				break;
			case 2:
				printf("Enter the element to be inserted \n");
				scanf("%d",&a);
				Binsert(a);
				break;
			case 3:
				Display();
				break;
			case 4:
				Bdelete();
				break;
			case 5:
				Search(a);
				break;
			case 6:
				Edelete();
				break;
			case 7:exit(0);
 			default: printf("Enter the choice Correctly");
			break;
		}

	}
}
