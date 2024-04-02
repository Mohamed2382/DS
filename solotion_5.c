/*
 ============================================================================
 Name        : solution_5.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//5-Write a C program to implement two stacks in a single array and performs push and pop operations for both stacks.

#include <stdio.h>

#define MAX_SIZE 100

// Global stack and top variables for two stacks
int stack[MAX_SIZE];
int top1 = -1; // Top of stack 1
int top2 = MAX_SIZE; // Top of stack 2

// Function to push an element onto stack 1
void push1(int data) {
    if (top1 == top2 - 1) {
        printf("Overflow stack!\n");
        return;
    }
    top1++;
    stack[top1] = data;
}

// Function to pop an element from stack 1
int pop1() {
    if (top1 == -1) {
        printf("Empty Stack!\n");
        return -1;
    }
    int data = stack[top1];
    top1--;
    return data;
}

// Function to push an element onto stack 2
void push2(int data) {
    if (top2 == top1 + 1) {
        printf("Overflow stack!\n");
        return;
    }
    top2--;
    stack[top2] = data;
}

// Function to pop an element from stack 2
int pop2() {
    if (top2 == MAX_SIZE) {
        printf("Empty Stack!\n");
        return -1;
    }
    int data = stack[top2];
    top2++;
    return data;
}

// Main function
int main() {
    // Input data in stack-1
    push1(10);
    push1(30);
    push1(40);
    push1(50);

    // Input data in stack-2
    push2(20);
    push2(40);
    push2(50);
    push2(60);
    push2(70);

    // Print elements in stack-1
    printf("Elements in Stack-1 are: ");
    while (top1 != -1) {
        printf("%d ", pop1());
    }
    printf("\n");

    // Print elements in stack-2
    printf("Elements in Stack-2 are: ");
    while (top2 != MAX_SIZE) {
        printf("%d ", pop2());
    }
    printf("\n");

    return 0;
}
