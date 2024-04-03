/*
 ============================================================================
 Name        : queue_4.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//4- implementation of a circular queue using an array

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the circular queue
struct CircularQueue {
    int items[MAX_SIZE]; // Array to store elements of the queue
    int front; // Index of the front element
    int rear; // Index of the rear element
};

// Function to create a new circular queue
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue)); // Allocate memory for the queue
    queue->front = -1; // Initialize front to -1 (indicating an empty queue)
    queue->rear = -1; // Initialize rear to -1 (indicating an empty queue)
    return queue; // Return the newly created queue
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front); // Check if next index of rear is equal to front
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1); // Check if both front and rear are -1 (indicating an empty queue)
}

// Function to add an element to the circular queue
void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) { // Check if the queue is full
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) { // Check if the queue is empty
        queue->front = 0; // If empty, set both front and rear to 0
        queue->rear = 0;
        queue->items[queue->rear] = value; // Add the new element to the rear of the queue
    }
    else {
        queue->rear = (queue->rear + 1) % MAX_SIZE; // Move the rear pointer to the next index (taking modulus to ensure circularity)
        queue->items[queue->rear] = value; // Add the new element to the rear of the queue
    }
}

// Function to remove an element from the circular queue
int dequeue(struct CircularQueue* queue) {
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
        queue->front = (queue->front + 1) % MAX_SIZE; // Move the front pointer to the next index (taking modulus to ensure circularity)
    }
    return item; // Return the removed element
}

// Function to return the front element of the circular queue without removing it
int peek(struct CircularQueue* queue) {
    if (isEmpty(queue)) { // Check if the queue is empty
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front]; // Return the element at the front of the queue
}

// Function to display the elements of the circular queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) { // Check if the queue is empty
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = queue->front;
    do {
        printf("%d ", queue->items[i]); // Print each element
        i = (i + 1) % MAX_SIZE; // Move to the next index (taking modulus to ensure circularity)
    } while (i != (queue->rear + 1) % MAX_SIZE); // Continue until we reach one position beyond the rear
    printf("\n");
}
int main() {
    struct CircularQueue* queue = createCircularQueue(); // Create a new circular queue

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

