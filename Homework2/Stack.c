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
