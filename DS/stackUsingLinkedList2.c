// Improvised code - easier version

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*root = NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void push(int data){    
    struct Node* newNode = createNode(data);
    newNode -> next = root;
    root = newNode;
    printf("\n%d is pushed\n",data);
}

void pop(){
    if(root == NULL){
        printf("\nStack is underflow\n");
        return;
    }

    struct Node* temp = root;
    root = root ->next;
    printf("\n%d is popped\n",temp->data);
    free(temp);
}

void peep(){
    if(root == NULL){
        printf("\nStack is underflow\n");
        return;
    }
    printf("\n%d is top most element\n",root->data);
}

void display(){
    if(root == NULL){
        printf("\nStack is underflow\n");
        return;
    }

    struct Node* temp = root;
    while(temp != NULL){
        printf("%d ->",temp -> data);
        temp = temp->next;
    }
    printf("\n");
}


void main(){
    int ch, n;
    while (1)
    {
    
    printf("1 Push\n2 Pop\n3 Peep\n4 Display\n5 Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        printf("\nEnter data to insert: ");
        scanf("%d",&n);
        push(n);
        break;
    case 2:
        pop();
        break;
    case 3:
        peep();
        break;
    case 4:
        display();
        break;
    case 5:
        exit(0);

    default:
        break;
    }
}
}
