#include "Stack.h"

#include <stdio.h>

bool isStackEmpty(Stack_t* stack)
{
    if (stack == NULL) {
        printf("In function isStackEmpty(): Stack pointer null!");
        return false;
    }

    return stack->top == 0;
}

bool isStackFull(Stack_t* stack)
{
    if (stack == NULL) {
        printf("In function isStackFull(): Stack pointer null!");
        return false;
    }

    return stack->top == MAX_ELEMENT_COUNT;
}

bool pushToStack(Stack_t* stack, int value)
{
    if (stack == NULL) {
        printf("In function pushToStack(): Unable to push data to stack. Stack pointer null!");
        return false;
    }

    if (isStackFull(stack)) {
        printf("In function pushToStack(): Unable to push data to stack. Stack full!");
        return false;
    }

    stack->item[stack->top++] = value;

    return true;
}
