#pragma once

typedef struct {
    int value;
    struct LinkedListNode* next;
} LinkedListNode;

// Creates linked list node and returns the pointer of the created node
LinkedListNode* createNode();
