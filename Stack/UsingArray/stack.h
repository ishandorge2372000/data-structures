#include <stdio.h>
#define MAX 15

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack overflow. Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("Pushed %d to stack.\n", value);
}

int pop()
{
    if(top == -1)
    {
        printf("Stack underflow. Cannot pop from stack.\n");
        return -1;
    }
    int poppedValue = stack[top--];
    printf("Popped %d from stack.\n", poppedValue);
    return poppedValue;
}

int peek()
{
    if(top == -1)
    {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return stack[top];
}

