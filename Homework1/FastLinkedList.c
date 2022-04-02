#include "FastLinkedList.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT_COUNT 10

int calculateMaxLevelSize(int arrayLength)
{
    int levelSize = 2; /* Level 1 and Last Level(Empty Level) is guaranteed. */
    int tempArrayLength = arrayLength;

    while (tempArrayLength > 1) {
        tempArrayLength = (tempArrayLength + 1) / 2;
        levelSize++;
    }

    return levelSize;
}

FastLinkedListNode_t* createFastLinkedListNode()
{
    // TODO : initializes all bytes in the allocated storage to zero
    FastLinkedListNode_t* newNode = (FastLinkedListNode_t*)malloc(sizeof(FastLinkedListNode_t));

    if (newNode == NULL) {
        printf("In function createFastLinkedListNode(): Memory allocation error");
        exit(EXIT_FAILURE);
    }

    newNode->previous = NULL;
    newNode->next = NULL;
    newNode->value = NULL;
}

FastLinkedListNode_t* insertHead(FastLinkedListNode_t* tail, DoublyLinkedListNode_t* value)
{
    FastLinkedListNode_t* newNode = createFastLinkedListNode();
    tail->next = newNode;

    newNode->previous = tail;
    newNode->next = NULL;
    newNode->value = value;

    return newNode;
}

void printHeads(FastLinkedListNode_t* tail)
{
    printf("********************* Heads *********************\n");

    // Reversed print operation
    for (FastLinkedListNode_t* current = tail; current != NULL; current = current->previous)
        if (current->value != NULL)
            printf("Node Address: 0x%x, Head Address Value: 0x%x\n", current, current->value);
}

FastLinkedListNode_t* createFastLinkedListLevels(FastLinkedListNode_t* headsOfFastLinkedList, DoublyLinkedListNode_t* downLevelHead, int downLevelNodeCount)
{
    static int level = 2;
    static FastLinkedListNode_t* tailOfHeadsLinkList = NULL;
    bool isAlreadyGenerated[MAX_ELEMENT_COUNT] = { 0 };

    int nodeCount = (downLevelNodeCount + 1) / 2;

    // seed with current time
    srand((unsigned)time(NULL));

    int generatedNodeCount = 0;
    while (generatedNodeCount < nodeCount) {

        // Get random index to first linked list node
        int index = rand() % downLevelNodeCount;

        if (isAlreadyGenerated[index])
            continue;

        isAlreadyGenerated[index] = true;

        ++generatedNodeCount;
    }

    DoublyLinkedListNode_t* head = createNode();
    DoublyLinkedListNode_t* currentNode = NULL;
    DoublyLinkedListNode_t* tail = NULL;
    for (int index = 0; index < MAX_ELEMENT_COUNT; ++index) {

        if (isAlreadyGenerated[index] == false)
            continue;

        currentNode = getLinkedListNode(downLevelHead, index);

        if (tail == NULL)
            tail = insertNode(head, currentNode->value);
        else
            tail = insertNode(tail, currentNode->value);
    }

    printf("********************* %d. Level *********************\n", level++);
    printf("Head Address: 0x%x\n", head);
    printLinkedList(head);

    if (tailOfHeadsLinkList == NULL)
        tailOfHeadsLinkList = insertHead(headsOfFastLinkedList, downLevelHead);

    tailOfHeadsLinkList = insertHead(tailOfHeadsLinkList, head);

    if (nodeCount == 1) {
        return tailOfHeadsLinkList;
    }

    return createFastLinkedListLevels(tail, head, nodeCount);
}

void findValue(FastLinkedListNode_t* tailOfHeadsLinkedList, int searchedValue)
{
    // TODO: Use function coming from Batuhan :)
    int currentLevel = 5;
    // TODO: reverse search heads of linked list
    for (FastLinkedListNode_t* current = tailOfHeadsLinkedList; current != NULL; current = current->previous) {
        printf("Searching in the level %d...\n", currentLevel);
        if (current->value != NULL) {
            DoublyLinkedListNode_t* node = searchValueInLinkedList(current->value, searchedValue);

            if (node != NULL) {
                printf("Find in the %d. Level\n", currentLevel);
                return;
            }
        }

        --currentLevel;
    }

    printf("Value not find in any level!\n");
}