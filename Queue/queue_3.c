/*
 ============================================================================
 Name        : queue_3.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//3-implementation of a queue using an array 

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the queue
struct Queue {
    int items[MAX_SIZE]; // Array to store the elements of the queue
    int front; // Index of the front element
    int rear; // Index of the rear element
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); // Allocate memory for the queue
    queue->front = -1; // Initialize front to -1 (indicating an empty queue)
    queue->rear = -1; // Initialize rear to -1 (indicating an empty queue)
    return queue; // Return the newly created queue
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1); // Check if rear has reached the maximum index
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1); // Check if both front and rear are -1 (indicating an empty queue)
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) { // Check if the queue is full
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) { // Check if the queue is empty
        queue->front = 0; // If empty, set both front and rear to 0
        queue->rear = 0;
    } else {
        queue->rear++; // Move the rear pointer to the next index
    }
    queue->items[queue->rear] = value; // Add the new element to the rear of the queue
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) { // Check if the queue is empty
        printf("Queue is empty\n");
        return -1;
    }
    item = queue->items[queue->front]; // Get the element at the front of the queue
    if (queue->front == queue->rear) { // If there is only one element in the queue
        queue->front = -1; // Reset front and rear to -1 (indicating an empty queue)
        queue->rear = -1;
    } else {
        queue->front++; // Move the front pointer to the next index
    }
    return item; // Return the removed element
}

// Function to return the front element of the queue without removing it
int peek(struct Queue* queue) {
    if (isEmpty(queue)) { // Check if the queue is empty
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front]; // Return the element at the front of the queue
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) { // Check if the queue is empty
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) { // Iterate from front to rear
        printf("%d ", queue->items[i]); // Print each element
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(); // Create a new queue

    enqueue(queue, 10); // Add elements to the queue
    enqueue(queue, 20);
    enqueue(queue, 30);

    display(queue); // Display the elements of the queue

    printf("Front element: %d\n", peek(queue)); // Display the front element

    printf("Dequeued: %d\n", dequeue(queue)); // Dequeue elements
    printf("Dequeued: %d\n", dequeue(queue));

    display(queue); // Display the elements of the queue after dequeuing

    printf("Front element: %d\n", peek(queue)); // Display the front element again

    return 0;
}
