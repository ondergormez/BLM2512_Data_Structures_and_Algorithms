#pragma once

#include <stdbool.h>

typedef struct {
    int value;
    struct DoublyLinkedListNode* previous;
    struct DoublyLinkedListNode* next;
} DoublyLinkedListNode;

// Creates linked list node and returns the pointer of the created node
DoublyLinkedListNode* createNode();

// Prints all nodes in the linked list
void printLinkedList(DoublyLinkedListNode* head);

// Inserts new node from the front of the linked list
bool insertNode(DoublyLinkedListNode* head, int value);
