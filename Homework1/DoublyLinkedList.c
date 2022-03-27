#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

LinkedListNode* createNode()
{
    // TODO: initializes all bytes in the allocated storage to zero
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));

    if (newNode == NULL) {
        printf("In function createNode(): Memory allocation error");
        exit(EXIT_FAILURE);
    }

    return newNode;
}

void printLinkedList(LinkedListNode* head)
{
    for (LinkedListNode* current = head; current != NULL; current = current->next)
        printf("Node Address: 0x%p, Node Value: %d", current, current->value);
}
