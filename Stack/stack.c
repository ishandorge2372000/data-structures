#include <stdio.h>
#include "stack.h"

int main()
{
    push(10);
    push(20);
    push(30);
    printf("Top element is: %d\n", peek());
    pop();
    printf("Top element after pop is: %d\n", peek());
    return 0;
}