/*
 ============================================================================
 Name        : solution_12.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//12-Write a C program to implement a stack that supports push, pop, get middle, and delete middle elements.

#include <stdio.h>
#include <stdlib.h>

// Node structure to represent elements in the stack
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Stack structure with top, middle pointers, and a counter to track elements
struct Stack {
    struct Node* top;
    struct Node* middle;
    int ctr;
};

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = stack->top;

    // Update the middle pointer based on the number of elements
    if (stack->ctr == 0) {
        stack->middle = newNode;
    } else if (stack->ctr % 2 == 0) {
        stack->middle = stack->middle->prev;
    }

    // Update the previous pointer of the top node
    if (stack->top != NULL) {
        stack->top->prev = newNode;
    }

    // Update the top pointer and increment the counter
    stack->top = newNode;
    stack->ctr++;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->ctr == 0) {
        printf("Stack is underflow\n");
        return -1;
    }

    // Pop the top node
    struct Node* top_node = stack->top;
    int data = top_node->data;

    stack->top = top_node->next;

    if (stack->top != NULL) {
        stack->top->prev = NULL;
    }

    free(top_node);

    // Update the middle pointer based on the number of elements
    if (stack->ctr % 2 == 1) {
        stack->middle = stack->middle->next;
    }

    stack->ctr--;

    return data;
}

// Function to get the middle element of the stack
int get_middle(struct Stack* stack) {
    if (stack->ctr == 0) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->middle->data;
}

// Function to delete the middle element of the stack
void deleteMiddle(struct Stack* stack) {
    if (stack->ctr == 0) {
        printf("Stack is empty\n");
        return;
    }

    // Get the middle node
    struct Node* middle_node = stack->middle;

    // Update the pointers based on the number of elements
    if (stack->ctr == 1) {
        stack->top = NULL;
        stack->middle = NULL;
    } else {
        stack->middle = stack->ctr % 2 == 0 ? stack->middle->next : stack->middle->prev;
        middle_node->prev->next = middle_node->next;
        middle_node->next->prev = middle_node->prev;
    }

    free(middle_node);
    stack->ctr--;
}

// Function to print the elements of the stack
void printStack(struct Stack* stack) {
    if (stack->ctr == 0) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Stack stack = {NULL, NULL, 0}; // Initialize the stack

    // Push elements onto the stack
    push(&stack, 23);
    push(&stack, 32);
    push(&stack, 26);
    push(&stack, 15);
    push(&stack, 88);

    // Display the stack elements
    printf("Stack elements: ");
    printStack(&stack);

    // Display the middle element
    printf("Middle element: %d\n", get_middle(&stack));

    // Delete the middle element
    printf("\nDelete the middle element of the stack:\n");
    deleteMiddle(&stack);

    // Display the updated stack and middle element
    printf("\nStack elements: ");
    printStack(&stack);
    printf("Middle element: %d\n", get_middle(&stack));

    // Delete another middle element
    printf("\nDelete the middle element of the stack:\n");
	deleteMiddle(&stack);

    // Display the updated stack and middle element
    printf("\nStack elements: ");
    printStack(&stack);
    printf("Middle element: %d\n", get_middle(&stack));

    return 0;
}
