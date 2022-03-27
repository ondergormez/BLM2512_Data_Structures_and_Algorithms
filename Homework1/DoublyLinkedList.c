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
