#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = insertAtBeginning(head, 10);
    printList(head);
    return 0;
}