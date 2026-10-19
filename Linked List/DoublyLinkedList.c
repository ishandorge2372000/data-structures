#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 20;
    head->prev = NULL;
    head->next = NULL;
    printf("Initial list: ");
    printList(head);
    printf("\n");
    printf("Inserting 10 at the beginning...\n");
    head = insertAtBeginning(head, 10);
    printList(head);
    printf("\nInserting 30 at the end...\n");
    head = insertAtEnd(head, 30);
    printList(head);
    printf("\nInserting 25 at position 3:\n");
    head = insertAtPosition(head, 25, 3);
    printList(head);

    printf("\nDeleting node at position 1:\n");
    head = deleteAtPosition(head, 1);
    printList(head);

    printf("\nDeleting node at position 2:\n");
    head = deleteAtPosition(head, 2);
    printList(head);

    printf("\nDeleting node at position 3:\n");
    head = deleteAtPosition(head, 3);
    printList(head);

    printf("\nDeleting node at position 4:\n");
    head = deleteAtPosition(head, 4);
    printList(head);
    return 0;
}