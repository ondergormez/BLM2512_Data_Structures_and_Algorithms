#include <stdio.h>
#include <stdbool.h>

#include "DoublyLinkedList.h"
#include "FastLinkedList.h"

int main(void)
{
    printf("Fast Linked List Implementation\n");
    // FastLinkedListNode_t* list = NULL; // TODO: malloc and zerois
    DoublyLinkedListNode_t* firstLevelHead = createNode();

    DoublyLinkedListNode_t* tail = insertNode(firstLevelHead, 0);
    tail = insertNode(tail, 1);
    tail = insertNode(tail, 2);
    tail = insertNode(tail, 3);
    tail = insertNode(tail, 4);
    tail = insertNode(tail, 5);
    tail = insertNode(tail, 6);
    tail = insertNode(tail, 7);
    tail = insertNode(tail, 8);
    tail = insertNode(tail, 9);

    printLinkedList(firstLevelHead);

    int length = getLinkedListLength(firstLevelHead);
    printf("Length of the linked list: %d\n", length);

    //    createLevel((length + 1) / 2);

    DoublyLinkedListNode_t* currentNode = getLinkedListNode(firstLevelHead, 7);
    printNode(currentNode);

    currentNode = getLinkedListNode(firstLevelHead, 12);

    printf("********************* 1. Level *********************\n");
    printf("Head Address: 0x%x\n", firstLevelHead);
    printLinkedList(firstLevelHead);

    FastLinkedListNode_t* headsOfFastLinkedList = createFastLinkedListNode();
    FastLinkedListNode_t* tailOfHeadsLinkedList = createFastLinkedListLevels(headsOfFastLinkedList, firstLevelHead, length);
    printHeads(tailOfHeadsLinkedList);

    findValue(tailOfHeadsLinkedList, 8);

    return 0;
}
