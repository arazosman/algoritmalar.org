// Stack Implementation for C Programming Language
// algoritmalar.org © 2019

#include <stdio.h>
#include <stdlib.h>
#include "stack.h" // stack fonksiyonlarını bu dosyanın içine yazdık

int main()
{
    STACK *stack = (STACK *)malloc(sizeof(STACK));
    initializeStack(stack);

    int choice = 1, val, i;

    while (choice >= 1 && choice <= 3)
    {
        printf("\npush: 1, pop: 2, print: 3, exit: 0: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("enter the value: ");
            scanf("%d", &val);

            if (pushToStack(stack, val))
                printf("%d pushed to stack\n", val);
            else
                printf("could not be pushed, no more space in the stack\n");
        }
        else if (choice == 2)
        {
            val = popFromStack(stack);

            if (val != -1)
                printf("popped value: %d\n", val);
            else
                printf("there is no element in the stack\n");
        }
        else if (choice == 3)
            printStack(stack);
    }

    return 0;
}
