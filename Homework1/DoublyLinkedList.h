#pragma once

typedef struct {
    int value;
    struct DoublyLinkedListNode* next;
} DoublyLinkedListNode;

// Creates linked list node and returns the pointer of the created node
LinkedListNode* createNode();

// Prints all nodes in the linked list
void printLinkedList(LinkedListNode* head);