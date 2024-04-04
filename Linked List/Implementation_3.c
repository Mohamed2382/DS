/*
 ============================================================================
 Name        : implementation_3.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//3- Find length of Linked List- Iterative approach
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in a linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the linked list
};

// Declare a global variable 'head' which points to the first node of the linked list
struct Node* head = NULL;

// Function to find the length of the linked list using an iterative approach
int findLengthIterative() {
    int length = 0;
    struct Node* current = head; // Start from the head of the list

    // Traverse the list and count the number of nodes encountered
    while (current != NULL) {
        length++;
        current = current->next; // Move to the next node
    }

    return length;
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

    // Find the length of the linked list
    int length = findLengthIterative();
    printf("Length of the linked list: %d\n", length);

    // Free allocated memory
    free(first);
    free(second);
    free(third);

    return 0;
}
