#ifndef __linkedlist_h__
#define __linkedlist_h__

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
bool search(struct Node *head, int target);
bool searchRecursive(struct Node *head, int target);
void printLLWithAddresses(struct Node *head);
int size(struct Node *head);
void deleteNode(struct Node **head_ref, int position);

#endif