/*
 ============================================================================
 Name        : solution_9.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//9-Write a C program to implement two stacks using a single array.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Global stack and top variables for two stacks
int stack[MAX_SIZE];
int top1 = -1, top2 = MAX_SIZE;

// Function to push an element onto a specific stack
void push(int stack_num, int val) {
    // Check for overflow condition
    if (top1 + 1 == top2) {
        printf("Overflow stack!\n");
        return;
    }
    // Check for stack number and push element accordingly
    if (stack_num == 1) {
        top1++;
        stack[top1] = val;
    } else {
        top2--;
        stack[top2] = val;
    }
}

// Function to pop an element from a specific stack
int pop(int stack_num) {
    // Check for stack number and pop element accordingly
    if (stack_num == 1) {
        // Check for underflow condition in stack 1
        if (top1 == -1) {
            printf("Empty stack!\n");
            return -1;
        }
        // Pop element from stack 1
        int val = stack[top1];
        top1--;
        return val;
    } else {
        // Check for underflow condition in stack 2
        if (top2 == MAX_SIZE) {
            printf("Stack Underflow\n");
            return -1;
        }
        // Pop element from stack 2
        int val = stack[top2];
        top2++;
        return val;
    }
}

int main() {
    // Push elements onto different stacks
    push(1, 1);
    push(1, 2);
    push(1, 3);
    push(2, 10);
    push(2, 20);
    push(2, 30);

    // Pop elements from different stacks and display
    printf("%d popped from stack 1\n", pop(1));
    printf("%d popped from stack 1\n", pop(1));
    printf("%d popped from stack 1\n", pop(1));
    printf("\n%d popped from stack 2\n", pop(2));
    printf("%d popped from stack 2\n", pop(2));
    printf("%d popped from stack 2\n", pop(2));

    return 0;
}
