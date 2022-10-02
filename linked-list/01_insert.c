#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *node)
{
    printf("{");
    while (node != NULL)
    {
        if (node->next == NULL)
            printf(" %d ", node->data);
        else
            printf(" %d,", node->data);

        node = node->next;
    }
    printf("}\n");
}

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    // inserted node is the new head
    (*head_ref) = new_node;
}

void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return;
}

bool search(struct Node *head, int x)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;

    append(&head, 6);
    push(&head, 7);
    push(&head, 10);
    push(&head, 5);
    append(&head, 3);
    insertAfter(head->next->next, 11);
    printLinkedList(head);

    search(head, 10) ? printf("%d is present \n", 10) : printf("%d is not present \n", 10);
    search(head, 9) ? printf("%d is present \n", 9) : printf("%d is not present \n", 9);

    return 0;
}
