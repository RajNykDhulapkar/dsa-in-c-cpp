#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *node);
void push(struct Node **head_ref, int new_data);
void insertAfter(struct Node *prev_node, int new_data);
void append(struct Node **head_ref, int new_data);

bool search(struct Node *head, int target)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == target)
            return true;
        current = current->next;
    }
    return false;
}

bool search_recursive(struct Node *head, int target)
{
    if (head == NULL)
        return false;

    if (head->data == target)
        return true;

    return search_recursive(head->next, target);
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;

    append(&head, 2);
    push(&head, 12);
    push(&head, 11);
    push(&head, 9);
    append(&head, 71);
    insertAfter(head->next->next, 13);
    printLinkedList(head);

    search(head, 69) ? printf("%d is present \n", 69) : printf("%d is not present \n", 69);
    search(head, 9) ? printf("%d is present \n", 9) : printf("%d is not present \n", 9);
    search_recursive(head, 71) ? printf("%d is present \n", 71) : printf("%d is not present \n", 71);
    search_recursive(head, 17) ? printf("%d is present \n", 17) : printf("%d is not present \n", 17);

    return 0;
}

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