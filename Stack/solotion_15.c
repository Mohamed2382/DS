/*
 ============================================================================
 Name        : solution_15.c
 Author      : Mohamed Yahya
 ============================================================================
 */

// Implement order of operations using a stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

// Define a struct for the stack
struct Stack {
    double items[MAX_SIZE];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, double data) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack is full\n");
    } else {
        stack->top++;
        stack->items[stack->top] = data;
    }
}

double pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1; // Return some error value indicating failure
    } else {
        double data = stack->items[stack->top];
        stack->top--;
        return data;
    }
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOperation (double operand1, double operand2, char op) {
    switch(op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0;
    }
}

double evaluateExpression(const char *expression) {
    struct Stack operands;
    initStack(&operands);

    struct Stack operators;
    initStack(&operators);

    int i;
    double operand = 0;
    int operand_flag = 0; // Flag to track if we are currently building an operand
    int sign = 1; // Sign of the current operand, initialized to positive

    for (i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            // Build the operand
            operand = operand * 10 + (expression[i] - '0');
            operand_flag = 1;
        } else {
            // Handle operators
            if (operand_flag) {
                // Push the operand onto the stack
                push(&operands, sign * operand);
                operand = 0; // Reset the operand
                operand_flag = 0;
                sign = 1; // Reset sign
            }

            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
                while (!isEmpty(&operators) && precedence(operators.items[operators.top]) >= precedence(expression[i])) {
                    double operand2 = pop(&operands);
                    double operand1 = pop(&operands);
                    char op = pop(&operators);
                    push(&operands, applyOperation(operand1, operand2, op));
                }
                push(&operators, expression[i]);
            } else if (expression[i] == '(') {
                push(&operators, expression[i]);
            } else if (expression[i] == ')') {
                while (!isEmpty(&operators) && operators.items[operators.top] != '(') {
                    double operand2 = pop(&operands);
                    double operand1 = pop(&operands);
                    char op = pop(&operators);
                    push(&operands, applyOperation(operand1, operand2, op));
                }
                pop(&operators); // Discard the '('
            }
        }
    }

    // Push the last operand onto the stack if present
    if (operand_flag) {
        push(&operands, sign * operand);
    }

    while (!isEmpty(&operators)) {
        double operand2 = pop(&operands);
        double operand1 = pop(&operands);
        char op = pop(&operators);
        push(&operands, applyOperation(operand1, operand2, op));
    }

    return pop(&operands);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter an arithmetic expression: ");
    fgets(expression, MAX_SIZE, stdin);

    double result = evaluateExpression(expression);
    printf("Result: %.2f\n", result);

    return 0;
}
