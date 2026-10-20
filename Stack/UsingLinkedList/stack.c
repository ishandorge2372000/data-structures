#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    struct node *stack = NULL;
    while (1) 
    {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Show Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        struct node *topElement = NULL;
        int choice, data;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                stack = push(stack, data);
                break;
            case 2:
                stack = pop(stack);
                break;
            case 3:
                topElement = peek(stack);
                if (topElement != NULL) {
                    printf("Top element is: %d\n", topElement->data);
                }
                break;
            case 4:
                printf("Stack elements: ");
                struct node *current = stack;
                while (current != NULL) {
                    printf("%d ", current->data);
                    current = current->next;
                }
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
   
    return 0;
}