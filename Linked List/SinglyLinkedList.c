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

struct node * deleteFirstNode(struct node *head_ref)
{
    if(head_ref == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return head_ref;
    }

    struct node *firstNode = head_ref;
    head_ref = head_ref->next;
    free(firstNode);
    return head_ref;
}

struct node * deleteLastNode(struct node *head_ref)
{
    if(head_ref == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return head_ref;
    }

    if(head_ref->next == NULL)
    {
        free(head_ref);
        return NULL;
    }

    struct node *current = head_ref;
    while(current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

    return head_ref;
}

struct node * deleteNodeAtPosition(struct node *head_ref, int position)
{
    if(head_ref == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return head_ref;
    }

    struct node *current = head_ref;

    if(position == 0)
    {
        head_ref = current->next;
        free(current);
        return head_ref;
    }

    for(int i = 1; i < position - 1 ; i++, current = current->next);
    
    struct node *nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    free(nodeToDelete);

    return head_ref;
}

void deleteAllNodes(struct node *head)
{
    struct node *current = head;

    while(head != NULL)
    {
        head = head->next;
        free(current);
        current = head;
    }
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

    printf("\nDelete the first node from a list:");
    head = deleteFirstNode(head);
    printList(head);
    
    printf("\nDelete the last node from a list:");
    head = deleteLastNode(head);
    printList(head);

    printf("\nDelete the node at position 2 from a list:");
    head = deleteNodeAtPosition(head, 2);
    printList(head);

    deleteAllNodes(head);
    printf("\nAll nodes deleted. List is now empty.\n");
    return 0;
}

/*  
Output:
10  20  15  
Number of nodes: 3
Inserting 25 at the end of the list.
10  20  15  25  
Inserting 1 at the beginning of the list.
1  10  20  15  25  
Inserting 30 at position 3 of the list.
1  10  30  20  15  25  
Delete the first node from a list:10  30  20  15  25  
Delete the last node from a list:10  30  20  15  
Delete the node at position 2 from a list:10  30  15  
All nodes deleted. List is now empty.
*/