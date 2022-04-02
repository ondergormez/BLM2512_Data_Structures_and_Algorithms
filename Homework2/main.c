#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>

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

int getRequiredBitCountForSigned(signed long value)
{
    if (value >= -128)
        return 8;

    if (value >= -32768)
        return 16;

    if (value >= -8388608)
        return 24;

    return 32;
}

/* It is responsibility to free the memory caller side  */
const char* convertToString(unsigned long value, int bitCount)
{
    int index = bitCount - 1;
    char* string = (char*)malloc(sizeof(char) * (bitCount + 1));
    string[bitCount] = NULL;

    if (string == NULL) {
        printf("In function convertToString(): Memory allocation error");
        exit(EXIT_FAILURE);
    }

    while (value != 0) {
        if (value % 2)
            string[index--] = '1';
        else
            string[index--] = '0';

        value /= 2;
    }

    while (index >= 0)
        string[index--] = '0';

    return string;
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