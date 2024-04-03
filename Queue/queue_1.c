/*
 ============================================================================
 Name        : queue_1.c
 Author      : Mohamed Yahya
 ============================================================================
 */

// 1-Implementation of a queue using a singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void Enqueue(int data) {
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->data = data;
    NewNode->next = NULL; // New node's next should be NULL as it will be the last node

    if (front == NULL) { // If the queue is empty, both front and rear will point to the new node
        front = rear = NewNode;
        return;
    }
    rear->next = NewNode; // Link the new node with the previous last node
    rear = NewNode; // Move rear to the newly added node
}

int Dequeue(void) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    } else {
        struct node* temp = front;
        int data = front->data;
        front = front->next;
        free(temp);
        return data;
    }
}

void display(void) {
    struct node* temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);

    display();

    printf("Dequeue is %d\n", Dequeue());
    printf("Dequeue is %d\n", Dequeue());
    printf("Dequeue is %d\n", Dequeue());

    display();

    return 0;
}
