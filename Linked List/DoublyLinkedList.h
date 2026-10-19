struct node 
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node * insertAtBeginning(struct node *head, int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    head = newNode; // Update head to point to the new node
    return head; // New head of the list
}

void printList(struct node *head)
{
    struct node *current = head;
   for( ; current != NULL; current = current->next)
    {
        printf("%d  ", current->data);
    }
}