#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* head = NULL; 
int count = 0;    
int MAX_SIZE = 0; 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegin(int data) {
    if (count >= MAX_SIZE) {
        printf("List is full! Cannot insert more elements.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    count++;
}

void insertAtEnd(int data) {
    if (count >= MAX_SIZE) {
        printf("List is full! Cannot insert more elements.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    count++;
}

void insertInMiddle(int data, int position) {
    if (count >= MAX_SIZE) {
        printf("List is full! Cannot insert more elements.\n");
        return;
    }

    if (position <= 1) {
        insertAtBegin(data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    count++;
}

void deleteAtBegin() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    count--;
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) 
        head = NULL;
    else
        prev->next = NULL;

    free(temp);
    count--;
}

void deleteInMiddle(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (position == 1) {
        head = temp->next;
        free(temp);
        count--;
        return;
    }

    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    count--;
}

void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void searchList(int data) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    int pos = 0;
    while (temp != NULL) {
        if(temp->data == data){
            printf("%d is at position %d", temp->data, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
}

int main() {
    int choice, data, position;

    printf("Enter the maximum number of elements for the list: ");
    scanf("%d", &MAX_SIZE);

    while (1) {
        printf("\n--- Linked List Operations Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at a Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from a Position\n");
        printf("7. Display List\n");
        printf("8. Find an element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBegin(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertInMiddle(data, position);
                break;
            case 4:
                deleteAtBegin();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteInMiddle(position);
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Enter an element to find in list: ");
                scanf("%d",&data);
                searchList(data);
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");

        }
    }
    return 0;
}
