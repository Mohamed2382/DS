/*
 ============================================================================
 Name        : queue_2.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//2- Implementation of a circular queue using a singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;           // Data of the node
    struct node* next;  // Pointer to the next node
};

struct node* rear = NULL;   // Rear pointer to the circular queue
struct node* front = NULL;  // Front pointer to the circular queue

// Function to enqueue an element into the circular queue
void Enqueue(int data) {
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));  // Allocate memory for a new node
    NewNode->data = data;  // Set data of the new node
    NewNode->next = NULL;  // Initialize next pointer to NULL

    if (rear == NULL && front == NULL) { // If the queue is empty
        front = rear = NewNode;  // Make front and rear point to the new node
        rear->next = rear;       // Circular link to itself
    }
    else {
        rear->next = NewNode;  // Rear node points to the new node
        rear = NewNode;        // Update rear to point to the new node
        rear->next = front;    // Circular link: rear points to front
    }
}

// Function to dequeue an element from the circular queue
void Dequeue(void) {
    struct node* temp = front;  // Store the front node in a temporary variable

    if (rear == NULL && front == NULL) {  // If the queue is empty
        printf("queue is empty \n");      // Print message
        return ;                          // Exit the function
    }
    else if (front == rear ) {   // If there is only one element in the queue
        front = rear = NULL;     // Set front and rear to NULL
        free(temp);              // Free the memory of the temporary node
    }
    else {
        front = front->next;   // Move front to the next node
        rear->next = front;    // Update rear's next pointer to front
        free(temp);            // Free the memory of the temporary node
    }
}

// Function to display the elements of the circular queue
void display(void) {
    struct node* temp = front;  // Start from the front node

    if (rear == NULL && front == NULL) {  // If the queue is empty
        printf("Queue is empty\n");        // Print message
        return;                            // Exit the function
    }

    do {
        printf("%d\t", temp->data);  // Print the data of the current node
        temp = temp->next;           // Move to the next node
    } while (temp != front);          // Repeat until back to the front node
}

// Function to retrieve the front element of the circular queue
int peek(void){
    if (rear == NULL && front == NULL){  // If the queue is empty
        printf ("queue is empty \n");    // Print message
        return -1 ;                      // Return an invalid value
    }
    else {
        int data  = front->data;   // Retrieve data of the front node
        return data;               // Return the data
    }
}

// Main function
int main() {
    display();             // Initially, the queue is empty, so display will show "Queue is empty"

    Enqueue(10);             // Enqueue element 10 into the queue
    Enqueue(20);             // Enqueue element 20 into the queue
    Enqueue(30);             // Enqueue element 30 into the queue
    display();               // Display the elements of the queue (should print: "10 20 30")
    Dequeue();               // Dequeue an element from the queue
    display();               // Display the elements of the queue after dequeue (should print: "20 30")

    return 0;
}

**********************************************************************************
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* rear = NULL; // Rear pointer is enough for circular queue

// Function to enqueue an element into the circular queue
void Enqueue(int data) {
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));
    if (NewNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    NewNode->data = data;
    if (rear == NULL) { // If the queue is empty
        rear = NewNode;
        rear->next = rear; // Circular link to itself
    } else {
        NewNode->next = rear->next; // New node points to the first node
        rear->next = NewNode; // Rear node points to the new node
        rear = NewNode; // Update rear to point to the new node
    }
}

// Function to dequeue an element from the circular queue
int Dequeue(void) {
    if (rear == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data;
    if (rear->next == rear) { // If there is only one node in the queue
        data = rear->data;
        free(rear);
        rear = NULL;
    } else {
        struct node* temp = rear->next; // Temporarily store the front node
        data = temp->data;
        rear->next = temp->next; // Rear points to the second node
        free(temp); // Free the memory allocated for the front node
    }
    return data;
}

// Function to display the elements of the circular queue
void display(void) {
    if (rear == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = rear->next; // Start from the first node
    printf("Queue elements are: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next); // Stop when we reach the rear node again
    printf("\n");
}

int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);

    display();

    printf("Dequeue is %d\n", Dequeue());
    printf("Dequeue is %d\n", Dequeue());
    printf("Dequeue is %d\n", Dequeue());

    Enqueue(30);

    display();

    return 0;
}
