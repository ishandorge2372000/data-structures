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
    head = newNode;
    return head;
}

struct node * insertAtEnd(struct node *head, int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) 
    {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }

    struct node *last = head;
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;

    return head;
}

struct node *insertAtPosition(struct node *head, int data, int position)
{
    if (position < 0)
        return head;

    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
        return head;

    newNode->data = data;

    if (position == 0)
    {
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return head;
    }

    struct node *current = head;

    for (int i = 1; current != NULL && i < position - 1; i++)
        current = current->next;

    if (current == NULL)
    {
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL)
        current->next->prev = newNode;

    current->next = newNode;
    return head;
}

void printList(struct node *head)
{
    struct node *current = head;
   for( ; current != NULL; current = current->next)
    {
        printf("%d  ", current->data);
    }
}