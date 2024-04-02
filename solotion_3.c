/*
 ============================================================================
 Name        : solution_3.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//3-Write a C program to check a stack is full or not using an array with push and pop operations.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int data) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full\n");
    } else {
        s->top++;
        s->items[s->top] = data;
    }
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1; // Return some error value indicating failure
    } else {
        int data = s->items[s->top];
        s->top--;
        return data;
    }
}

int main() {
    Stack myStack;
    initializeStack(&myStack);
    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);

    printf("%d is popped\n", pop(&myStack));
    printf("%d is popped\n", pop(&myStack));
    printf("%d is popped\n", pop(&myStack));

    return 0;
}
