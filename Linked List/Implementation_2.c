/*
 ============================================================================
 Name        : implementation_2.c
 Author      : Mohamed Yahya
 ============================================================================
 */

//2- Deletion of a node from Linked List (from beginning, end, specified position)
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in a linked list
struct Node {
	int data;           // Data stored in the node
	struct Node* next;  // Pointer to the next node in the linked list
};

// Declare a global variable 'head' which points to the first node of the linked list
struct Node* head = NULL;

// Function to delete the first node from the linked list
void deleteFromBeginning() {
	if (head == NULL) {
		printf("List is empty. Nothing to delete.\n");
		return;
	}
	struct Node* temp = head;
	head = head->next;
	free(temp);
}

// Function to delete the last node from the linked list
void deleteFromEnd() {
	if (head == NULL) {
		printf("List is empty. Nothing to delete.\n");
		return;
	}
	struct Node* temp = head;
	struct Node* prev = NULL;
	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == head) {
		head = NULL; // If the list has only one node
	}
	else {
		prev->next = NULL;
	}
	free(temp);
}

// Function to delete a node from a specified position in the linked list
void deleteFromPosition(int position) {
	if (head == NULL) {
		printf("List is empty. Nothing to delete.\n");
		return;
	}
	if (position < 1) {
		printf("Invalid position\n");
		return;
	}
	if (position == 1) {
		struct Node* temp = head;
		head = head->next;
		free(temp);
		return;
	}
	struct Node* temp = head;
	struct Node* prev = NULL;
	int i;
	for (i = 1; temp != NULL && i < position; i++) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("Position out of range\n");
		return;
	}
	prev->next = temp->next;
	free(temp);
}

int main (){
	// Your test cases or other code here
}
