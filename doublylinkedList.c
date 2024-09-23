#include <stdio.h>
#include <stdlib.h>

// Definition of the doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    newNode->next = *head; // Point the next of new node to current head
    
    if (*head != NULL) {
        (*head)->prev = newNode; // Update previous of current head to new node
    }
    
    *head = newNode; // Update head to new node
}
// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode; // Point the next of last node to new node
    newNode->prev = temp; // Point the previous of new node to last node
}
// Function to delete a node from the doubly linked list
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL) {
        return;
    }

    // If the node to be deleted is the head node
    if (*head == delNode) {
        *head = delNode->next;
    }

    // Change the next only if the node to be deleted is NOT the last node
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }

    // Change the prev only if the node to be deleted is NOT the first node
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }

    // Free the memory occupied by delNode
    free(delNode);
}
// Function to print the doubly linked list
void printList(struct Node* node) {
    struct Node* last;

    printf("Forward traversal: ");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");

    printf("Backward traversal: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;

    int n , value;
    printf("Enter the number of elements:\n");

    scanf("%d", &n);
    printf("Enter the elements: \n");

    for (int i = 0; i<n;i++){
        scanf("%d",&value);
        insertAtEnd(&head,value);

    }

    // Print the doubly linked list
    printList(head);

    // Delete a node (say the head node)
    deleteNode(&head, head);

    // Print the list again
    printList(head);

    return 0;
}
