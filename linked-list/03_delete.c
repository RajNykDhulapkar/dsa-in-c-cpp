#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *node);
void push(struct Node **head_ref, int new_data);
void insertAfter(struct Node *prev_node, int new_data);
void append(struct Node **head_ref, int new_data);
bool search(struct Node *head, int target);
bool search_recursive(struct Node *head, int target);

void printLLWithAddresses(struct Node *head)
{
    while (head)
    {
        printf("[ %i, nxt 0x%x] addr (0x%x) \n", head->data, head->next, head);
        head = head->next;
    }
    printf("\n");
}

int size(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void deleteNode(struct Node **head_ref, int position)
{
    struct Node *temp;
    struct Node *prev;
    temp = *head_ref;
    prev = *head_ref;

    for (int i = 0; i < position; i++)
    {
        if (i == 0 && position == 1)
        {
            *head_ref = (*head_ref)->next;
            free(temp);
            return;
        }
        else
        {
            if (i == position - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
                return;
            }
            else
            {
                prev = temp;
                if (prev == NULL)
                    return;
                temp = temp->next;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;

    append(&head, 12);
    push(&head, 12);
    push(&head, 11);
    push(&head, 19);
    append(&head, 71);
    insertAfter(head->next->next, 13);
    printLinkedList(head);

    printLLWithAddresses(head);
    printf("size is %d\n", size(head));
    printLinkedList(head);
    deleteNode(&head, 3);
    printLinkedList(head);

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