/*
 ============================================================================
 Name        : queue_5.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//5-Implement Queue using Stack
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize a stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Structure to represent a queue
struct Queue {
    struct Stack enqueueStack;
    struct Stack dequeueStack;
};

// Function to initialize a queue
void initializeQueue(struct Queue* queue) {
    initializeStack(&queue->enqueueStack);
    initializeStack(&queue->dequeueStack);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(&queue->enqueueStack)) {
        printf("Queue is full\n");
        return;
    }
    // Move all elements from dequeue stack to enqueue stack
    while (!isEmpty(&queue->dequeueStack)) {
        push(&queue->enqueueStack, pop(&queue->dequeueStack));
    }
    // Push the new element onto enqueue stack
    push(&queue->enqueueStack, value);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(&queue->enqueueStack) && isEmpty(&queue->dequeueStack)) {
        printf("Queue is empty\n");
        return -1;
    }
    // Move all elements from enqueue stack to dequeue stack
    while (!isEmpty(&queue->enqueueStack)) {
        push(&queue->dequeueStack, pop(&queue->enqueueStack));
    }
    // Pop the top element from dequeue stack
    return pop(&queue->dequeueStack);
}

// Function to return the front element of the queue without removing it
int peek(struct Queue* queue) {
    if (isEmpty(&queue->enqueueStack) && isEmpty(&queue->dequeueStack)) {
        printf("Queue is empty\n");
        return -1;
    }
    // Move all elements from enqueue stack to dequeue stack
    while (!isEmpty(&queue->enqueueStack)) {
        push(&queue->dequeueStack, pop(&queue->enqueueStack));
    }
    // Return the top element from dequeue stack without popping
    return queue->dequeueStack.items[queue->dequeueStack.top];
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", peek(&queue));

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    printf("Front element: %d\n", peek(&queue));

    return 0;
}
