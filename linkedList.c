#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
void append(Node **headRef, int data);
void updateNode(Node *head, int oldData, int newData);
void deleteNode(Node **headRef, int data);
void printList(Node *head);
void freeList(Node *head);

int main()
{
    Node *head = NULL;
    int choice, data, oldData, newData;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add node\n");
        printf("2. Update node\n");
        printf("3. Delete node\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to add: ");
            scanf("%d", &data);
            append(&head, data);
            break;

        case 2:
            printf("Enter old data to update: ");
            scanf("%d", &oldData);
            printf("Enter new data: ");
            scanf("%d", &newData);
            updateNode(head, oldData, newData);
            break;

        case 3:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;

        case 4:
            printf("Linked List: ");
            printList(head);
            break;

        case 5:
            freeList(head);
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node **headRef, int data)
{
    Node *newNode = createNode(data);
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    Node *temp = *headRef;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void updateNode(Node *head, int oldData, int newData)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == oldData)
        {
            temp->data = newData;
            return;
        }
        temp = temp->next;
    }
    printf("Node with data %d not found.\n", oldData);
}

void deleteNode(Node **headRef, int data)
{
    Node *temp = *headRef;
    Node *prev = NULL;

    if (temp != NULL && temp->data == data)
    {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with data %d not found.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
