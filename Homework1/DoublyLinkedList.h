#pragma once

#include <stdbool.h>

typedef struct DoublyLinkedListNode {
    int value;
    struct DoublyLinkedListNode* previous;
    struct DoublyLinkedListNode* next;
} DoublyLinkedListNode_t;

// TODO: Use DoublyLinkedListNode_t in all
// Creates linked list node and returns the pointer of the created node
DoublyLinkedListNode_t* createNode();

// Prints all nodes in the linked list
void printLinkedList(DoublyLinkedListNode_t* head);

void printNode(DoublyLinkedListNode_t* node);

// TODO: Inserts new node from the rear of the linked list
DoublyLinkedListNode_t* insertNode(DoublyLinkedListNode_t* tail, int value);

// TODO: Add comment
bool deleteNode(DoublyLinkedListNode_t* node);

int getLinkedListLength(DoublyLinkedListNode_t* head);

DoublyLinkedListNode_t* getLinkedListNode(DoublyLinkedListNode_t* head, int index);


DoublyLinkedListNode_t* searchValueInLinkedList(DoublyLinkedListNode_t* head, int searchedValue);
