/*
 ============================================================================
 Name        : solution_4.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//4-Write a C program that accepts a string and reverse it using a stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Increased maximum size for input string

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, char data) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack is full\n");
    } else {
        stack->top++;
        stack->items[stack->top] = data;
    }
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1; // Return some error value indicating failure
    } else {
        char data = stack->items[stack->top];
        stack->top--;
        return data;
    }
}

void reverseString(const char *str, char *result) {
    struct Stack stack;
    initStack(&stack);

    int i;
    for (i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }
    for (i = 0; str[i] != '\0'; i++) {
        result[i] = pop(&stack);
    }
    result[i] = '\0'; // Terminate the reversed string
}

int main() {
    char text[MAX_SIZE];
    char reversed[MAX_SIZE]; // Buffer for reversed string
    printf("Input a string: ");
    fgets(text, MAX_SIZE, stdin);

    reverseString(text, reversed);
    printf("Reversed string using a stack is: %s\n", reversed);

    return 0;
}

********************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Global stack and top variable declaration
char stack[MAX_SIZE];
int top = -1;

// Function to push a character onto the stack
void push(char data) {
    if (top == MAX_SIZE - 1) {
        printf("Overflow stack!\n");
        return;
    }
    top++;
    stack[top] = data;
}

// Function to pop a character from the stack
char pop() {
    if (top == -1) {
        printf("Empty Stack!\n");
        return '\0';
    }
    char data = stack[top];
    top--;
    return data;
}

// Function to reverse a string using a stack
void reverse_string(char *str) {
    int len = strlen(str);

    // Push each character of the string onto the stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    // Pop characters from the stack to reverse the string
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
}

// Main function
int main() {
    char text[MAX_SIZE];
    printf("Input a string: ");
    fgets(text, MAX_SIZE, stdin);

    // Remove newline character from input
    text[strcspn(text, "\n")] = '\0';

    // Reverse the input string using the stack
    reverse_string(text);

    // Print the reversed string
    printf("Reversed string using a stack is: %s\n", text);

    return 0;
}
