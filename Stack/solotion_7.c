/*
 ============================================================================
 Name        : solution_7.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//7-Write a C program that checks whether a string of parentheses is balanced or not using stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Global variables for stack and top
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
        printf("Empty stack!\n");
        return ' ';
    }
    char data = stack[top];
    top--;
    return data;
}

// Function to check if two characters form a matching pair of parentheses
int is_matching_pair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') {
        return 1;
    } else if (char1 == '[' && char2 == ']') {
        return 1;
    } else if (char1 == '{' && char2 == '}') {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the expression is balanced
int isBalanced(char* text) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == '(' || text[i] == '[' || text[i] == '{') {
            push(text[i]);
        } else if (text[i] == ')' || text[i] == ']' || text[i] == '}') {
            if (top == -1) {
                return 0; // If no opening bracket is present
            } else if (!is_matching_pair(pop(), text[i])) {
                return 0; // If closing bracket doesn't match the last opening bracket
            }
        }
    }
    if (top == -1) {
        return 1; // If the stack is empty, the expression is balanced
    } else {
        return 0; // If the stack is not empty, the expression is not balanced
    }
}

// Main function
int main() {
   char text[MAX_SIZE];
   printf("Input an expression in parentheses: ");
   scanf("%s", text);

   // Check if the expression is balanced or not
   if (isBalanced(text)) {
       printf("The expression is balanced.\n");
   } else {
       printf("The expression is not balanced.\n");
   }
   return 0;
}
