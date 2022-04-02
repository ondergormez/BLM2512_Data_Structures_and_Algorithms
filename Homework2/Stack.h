#pragma once

#define MAX_ELEMENT_COUNT 1000

typedef struct Stack {
    int item[MAX_ELEMENT_COUNT];
    int top;
} Stack_t;
