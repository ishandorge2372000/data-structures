#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    struct node *stack = NULL;
    stack = push(stack, 10);
    stack = push(stack, 20);
    stack = push(stack, 30);
    stack = push(stack, 40);
    stack = push(stack, 50);

    printf("Original Stack: ");
    showStack(stack);
    struct node *stack1 = (struct node *)malloc(sizeof(struct node));
    while (stack != NULL) 
    {
        stack1 = push(stack1, stack->data);
    }

    struct node *stack2 = (struct node *)malloc(sizeof(struct node));
    while (stack1 != NULL)
    {
        stack2 = push(stack2, stack1->data);
    }

    while (stack2 != NULL)
    {
        stack = pop(stack2);
    }
    printf("Reversed Stack: ");
    showStack(stack);
}