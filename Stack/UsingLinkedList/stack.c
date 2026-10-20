#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    struct node *stack = NULL;

    stack = push(stack, 10);
    stack = push(stack, 20);
    stack = push(stack, 30);

    struct node *topElement = peek(stack);
    printf("Top element is: %d\n", topElement->data);

    stack = pop(stack);

    topElement = peek(stack);
    printf("After popping, top element is: %d\n", topElement->data);

    return 0;
}