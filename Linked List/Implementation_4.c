/*
 ============================================================================
 Name        : implementation_4.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//4-Reverse a Linked List - Iterative Method
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in a linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the linked list
};

// Declare a global variable 'head' which points to the first node of the linked list
struct Node* head = NULL;

// Function to reverse the linked list using the iterative method
void reverseLinkedList() {
    struct Node *prevNode, *currentNode, *nextNode;
    prevNode = NULL;
    currentNode = nextNode = head;

    while (nextNode != NULL) {
        nextNode = nextNode->next; // Store the next node
        currentNode->next = prevNode; // Reverse the pointer

        // Move pointers one position ahead
        prevNode = currentNode;
        currentNode = nextNode;
    }

    head = prevNode; // Update head to point to the new first node
}

// Function to print the linked list
void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main (){
    // Example: Creating a linked list
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    // Assigning data values and linking nodes
    first->data = 1;
    first->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    // Point head to the first node
    head = first;

    printf("Original linked list: ");
    printList();

    // Reverse the linked list
    reverseLinkedList();

    printf("Reversed linked list: ");
    printList();

    // Free allocated memory
    free(first);
    free(second);
    free(third);

    return 0;
}
