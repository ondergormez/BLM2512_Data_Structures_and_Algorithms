#include "Stack.h"

int getRequiredBitCountForUnsigned(unsigned long value)
{
    if (value <= 255)
        return 8;

    if (value <= 65535)
        return 16;

    if (value <= 16777215)
        return 24;

    return 32;
}

int main(void)
{
    Stack_t stack = { 0 };
    int value = 0;

    pushToStack(&stack, 10);
    pushToStack(&stack, 15);
    pushToStack(&stack, 20);
    printValuesInStack(&stack);

    popFromStack(&stack, &value);
    printValuesInStack(&stack);

    peekValueFromStack(&stack, &value);
    printf("Peek value: %d\n", value);

    return 0;
}