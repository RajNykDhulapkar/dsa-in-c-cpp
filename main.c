#include <stdio.h>
#include "lib/linkedlist.c"

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

    return 0;
}
