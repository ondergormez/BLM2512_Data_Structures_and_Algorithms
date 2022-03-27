#include "DoublyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

DoublyLinkedListNode* createNode()
{
    // TODO: initializes all bytes in the allocated storage to zero
    DoublyLinkedListNode* newNode = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));

    if (newNode == NULL) {
        printf("In function createNode(): Memory allocation error");
        exit(EXIT_FAILURE);
    }

    return newNode;
}

void printLinkedList(DoublyLinkedListNode* head)
{
    for (DoublyLinkedListNode* current = head; current != NULL; current = current->next)
        printf("Node Address: 0x%p, Node Value: %d", current, current->value);
}
