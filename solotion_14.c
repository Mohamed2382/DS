/*
 ============================================================================
 Name        : solution_14.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//14-Write a C program to convert a decimal number to its binary equivalent using stack.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack data structure to store binary digits
struct Stack {
    int top; // Index for the top of the stack
    int array[MAX_SIZE]; // Array to hold elements of the stack
};

// Initialize a new stack
struct Stack* newStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); // Allocate memory for the stack
    stack->top = -1; // Set the top index to -1 (empty stack)
    return stack;
}

// Check if the stack is empty
int is_Empty(struct Stack* stack) {
    return (stack->top == -1); // Returns 1 if the stack is empty, otherwise 0
}

// Function to push an item to the stack
void push(struct Stack* stack, int item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Error: Stack full!\n"); // Display an error message if the stack is full
        return;
    }
    stack->array[++stack->top] = item; // Increment top index and add the item to the stack
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (is_Empty(stack)) {
        printf("Error: Stack underflow\n"); // Display an error message if the stack is empty
        return -1;
    }
    return stack->array[stack->top--]; // Return the top element and decrement top index
}

// Convert decimal to binary using stack
void decimal_to_binary(int decimal) {
    // Create a new stack to store binary digits
    struct Stack* stack = newStack();

    // Push the remainder onto the stack after dividing the decimal number by 2
    while (decimal > 0) {
        int remainder = decimal % 2; // Get the remainder when divided by 2
        push(stack, remainder); // Push the remainder onto the stack
        decimal /= 2; // Update the decimal number
    }

    // To get the binary equivalent of the digits, pop them from the stack and print them
    printf("Binary equivalent of the said number is: ");
    while (!is_Empty(stack)) {
        printf("%d", pop(stack)); // Print the binary equivalent by popping elements from the stack
    }
    printf("\n");
}

int main() {
    int dec_no;
    printf("Input a decimal number: ");
    scanf("%d", &dec_no); // Read a decimal number from the user
    decimal_to_binary(dec_no); // Convert the decimal number to binary
    return 0;
}

