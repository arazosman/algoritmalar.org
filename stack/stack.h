// Stack Library for C Programming Language
// algoritmalar.org © 2019

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

const int maxStackSize = 1024;

typedef struct
{
    int *st;
    int size, top;
} STACK;

void initializeStack(STACK *stack)
{
    stack->size = 4;
    stack->top = 0;
    stack->st = (int *)malloc(stack->size*sizeof(int));
}

int isStackFull(STACK *stack)
{
    if (stack->size == maxStackSize)
        return 1;

    if (stack->top == stack->size)
    {
        stack->size *= 2;
        stack->st = (int *)realloc(stack->st, stack->size);
    }

    return 0;
}

int isStackEmpty(STACK *stack)
{
    if (stack->top < stack->size/4)
    {
        stack->size /= 2;
        stack->st = (int *)realloc(stack->st, stack->size);
    }

    return stack->top == 0;
}

int pushToStack(STACK *stack, int val)
{
    if (isStackFull(stack))
        return 0;

    stack->st[stack->top++] = val;

    return 1;
}

int popFromStack(STACK *stack)
{
    if (isStackEmpty(stack))
        return -1;

    return stack->st[--stack->top];
}

int topOfStack(STACK *stack)
{
    return stack->st[stack->top];
}

void printStack(STACK *stack)
{
    printf("\nstack size: %d\n", stack->size);
    printf("top position of the stack: %d\n", stack->top);
    printf("stack elements: ");

    for (int i = 0; i < stack->top; ++i)
        printf("%d ", stack->st[i]);

    printf("\n\n");
}

#endif
