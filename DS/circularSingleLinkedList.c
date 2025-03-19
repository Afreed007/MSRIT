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
    if (head == NULL) {
        head = newNode;
        newNode->next = head; 
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
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
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        
        temp->next = newNode;
        newNode->next = head;
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
    for (int i = 1; temp->next != head && i < position - 1; i++)
        temp = temp->next;

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
    if (head->next == head) {
        head = NULL;
    } else {
        struct Node* last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
    }
    
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
    
    if (head->next == head) {
        head = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
    }

    free(temp);
    count--;
}

void deleteInMiddle(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (position == 1) {
        deleteAtBegin();
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; temp->next != head && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    count--;
}

void searchElement(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    int position = 1;

    do {
        if (temp->data == value) {
            printf("Element %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    printf("Element %d not found in the list.\n", value);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    int choice, data, position;

    printf("Enter the maximum number of elements for the list: ");
    scanf("%d", &MAX_SIZE);

    while (1) {
        printf("\n--- Circular Singly Linked List Operations Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at a Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from a Position\n");
        printf("7. Search for an Element\n");
        printf("8. Display List\n");
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
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchElement(data);
                break;
            case 8:
                displayList();
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
