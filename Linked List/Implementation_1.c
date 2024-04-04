/*
 ============================================================================
 Name        : implementation_1.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//1-Insertion of a Node in Linked List(at Beginning,End,Specified Position)

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in a linked list
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node in the linked list
};

// Declare a global variable 'head' which points to the first node of the linked list
struct Node* head = NULL;

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(int newData) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Set the data of the new node
    newNode->data = newData;
    // Set the next pointer of the new node to point to the current head
    newNode->next = head;
    // Update the head to point to the new node, making it the first node in the list
    head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(int newData) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Create a pointer 'last' to traverse the list to find the last node
    struct Node* last = head;
    // Set the data of the new node
    newNode->data = newData;
    // Set the next pointer of the new node to NULL, as it will be the last node
    newNode->next = NULL;
    // If the list is empty, make the new node as the head and return
    if (head == NULL) {
        head = newNode;
        return;
    }
    // Traverse the list to find the last node
    while (last->next != NULL)
        last = last->next;
    // Make the next pointer of the last node point to the new node
    last->next = newNode;
}

// Function to insert a new node at a specified position in the linked list
void insertAtPosition(int newData, int position) {
    // Check for invalid position (less than 1)
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    // If position is 1, call insertAtBeginning function
    if (position == 1) {
        insertAtBeginning(newData);
        return;
    }
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Set the data of the new node
    newNode->data = newData;
    // Create a pointer 'temp' to traverse the list
    struct Node* temp = head;
    // Traverse the list to find the node at position - 1
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    // If the position is out of range, print an error message and return
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    // Adjust pointers to insert the new node at the specified position
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList() {
    // Create a pointer 'temp' to traverse the list starting from the head
    struct Node* temp = head;
    // Traverse the list and print the data of each node
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Inserting nodes at the beginning
    insertAtBeginning(5);
    insertAtBeginning(10);
    printf("Linked list after inserting at the beginning: ");
    printList();

    // Inserting nodes at the end
    insertAtEnd(15);
    insertAtEnd(20);
    printf("Linked list after inserting at the end: ");
    printList();

    // Inserting node at a specified position
    insertAtPosition(25, 3);
    printf("Linked list after inserting at position 3: ");
    printList();

    return 0;
}
