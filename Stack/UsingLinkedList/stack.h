struct node {
    int data;
    struct node* next;
};

struct node *push(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory unavailable\n");
        return head;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

struct node *pop(struct node *head)
{
    if (head == NULL) {
        printf("Stack is empty\n");
        return head;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node *peek(struct node *head)
{
    if (head == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }
    return head;
}

void *showStack(struct node *head)
{
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}