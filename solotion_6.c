/*
 ============================================================================
 Name        : solution_6.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//6-Write a C program to sort a given stack using another stack.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Global stack arrays and top variable
int stack[MAX_SIZE]; // Original stack
int sorted_Stack[MAX_SIZE]; // Stack used for sorting
int top = -1; // Top of the original stack

// Function to push an element onto the original stack
void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Overflow stack!\n");
        return;
    }
    top++;
    stack[top] = data;
}

// Function to pop an element from the original stack
int pop() {
    if (top == -1) {
        printf("Empty Stack!\n");
        return -1;
    }
    int data = stack[top];
    top--;
    return data;
}

// Function to sort the original stack
void sort_stack() {
    int temp;
    int sortedTop = -1; // Top of the stack used for sorting

    // Sorting logic
    while (top != -1) {
        temp = pop();
        while (sortedTop != -1 && sorted_Stack[sortedTop] < temp) {
            push(sorted_Stack[sortedTop]);
            sortedTop--;
        }
        sortedTop++;
        sorted_Stack[sortedTop] = temp;
    }

    // Pushing sorted elements back to the original stack
    while (sortedTop != -1) {
        push(sorted_Stack[sortedTop]);
        sortedTop--;
    }
}

// Main function
int main() {
    // Push elements onto the original stack
    push(1);
    push(5);
    push(5);
    push(2);
    push(3);
    push(8);

    // Print original stack elements
    printf("Original stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    // Sort the original stack
    sort_stack();

    // Print sorted stack elements
    printf("Sorted stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}

