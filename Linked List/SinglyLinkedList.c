#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int countNodes(struct node *head)
{
    int count = 0;
    struct node *current = head;

    while(current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

struct node * insertAtBeginning(struct node *head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = head_ref;
    head_ref = new_node;
    return head_ref;
}

struct node * insertAtEnd(struct node *head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *last = head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if(head_ref == NULL)
    {
        head_ref = new_node;
        return head_ref;
    }

    while(last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return head_ref;
}

struct node * insertAtPosition(struct node *head_ref, int new_data, int position)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *current = head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if(position == 0)
    {
        new_node->next = head_ref;
        head_ref = new_node;
        return head_ref;
    }

    for(int i = 1; current != NULL && i < position - 1; i++)
    {
        current = current->next;
    }

    if(current == NULL)
    {
        printf("Position is greater than the number of nodes. Inserting at the end.\n");
        return insertAtEnd(head_ref, new_data);
    }

    new_node->next = current->next;
    current->next = new_node;

    return head_ref;
}

void printList(struct node *head)
{
    struct node *current = head;

    for( ; current != NULL; current = current->next)
    {
        printf("%d  ", current->data);
    }
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 20;
    current->next = NULL;
    head->next = current;

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = 15;
    new_node->next = NULL;
    current->next = new_node;

    printList(head);
    printf("\nNumber of nodes: %d\n", countNodes(head));
    printf("Inserting 25 at the end of the list.\n");
    head = insertAtEnd(head, 25);
    printList(head);

    printf("\nInserting 1 at the beginning of the list.\n");
    head = insertAtBeginning(head, 1);
    printList(head);

    printf("\nInserting 30 at position 3 of the list.\n");
    head = insertAtPosition(head, 30, 3);
    printList(head);
    return 0;
}