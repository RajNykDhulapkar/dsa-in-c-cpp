#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char const *argv[])
{
    struct Node *first = NULL; // head
    struct Node *second = NULL;
    struct Node *third = NULL;

    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    first->data = 1;
    first->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    printLinkedList(first);
    return 0;
}
