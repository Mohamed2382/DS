/*
 ============================================================================
 Name        : solution_2.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//2-Write a C program to implement a stack using a singly linked list.
#include <stdio.h>
#include <stdlib.h>

// Node structure to represent elements in the stack
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Function to push a value onto the stack
void push_data(int data) {
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->next = top;
    top = NewNode;
}

// Function to display the stack
void display(void) {
    struct Node* temp = top;
    if (top == NULL)
        printf("stack is empty\n");
    else {
        while (temp != NULL) {
            printf("%d is pushed\n", temp->data);
            temp = temp->next;
        }
    }
}

// Function to pop a value from the stack
int pop(void) {
    if (top == NULL) {
        printf("stack is empty\n");
        return -1; // Return an error value
    }
    struct Node* temp = top;
    int popped_value = temp->data;
    top = top->next;
    free(temp); // Free the memory allocated for the popped node
    return popped_value;
}

int main() {
    push_data(1);
    push_data(2);
    push_data(3);
    push_data(4);

    display();

    printf("Popped value: %d\n", pop());
    printf("Popped value: %d\n", pop());

    display();

    return 0;
}


