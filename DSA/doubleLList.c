#include <stdio.h>
#include <stdlib.h>
// creating the structure of node..//
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
// Traversal in straight order..//
void linkedlistTraversal(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
// Taversal in reverse order..//
void linkedlistTraversalrev(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *arr[1000];
    int i = 0;
    while (ptr != NULL)
    {
        arr[i] = ptr;
        ptr = ptr->next;
        i++;
    }

    for (i = i - 1; i >= 0; i--)
    {
        printf(" %d ", arr[i]->data);
    }
}

int main()
{
    struct Node *head; // first node or head node..//
    struct Node *second; // second node..//
    struct Node *third; // third node..//
    struct Node *fourth; // fourth node..//
    // allocation of memory in the heap (dynaminc memory allocation)//
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes..
    head->prev = NULL;
    head->data = 4;
    head->next = second;
    // link second and third nodes..
    second->prev = head;
    second->data = 3;
    second->next = third;
    // link third and fourth nodes of list nodes..
    third->prev = second;
    third->data = 6;
    third->next = fourth;
    // terminate fourth nodes..
    fourth->prev = third;
    fourth->data = 1;
    fourth->next = NULL;
   // printing the element of linked list in straight order..//
    printf("Elements in doubly linked list in straight order:\n");
    linkedlistTraversal(head);
    // printing the element of linked list in reverse order..//
    printf("Elements in doubly linked list in reverse ord:\n");
    linkedlistTraversalrev(head);
    return 0;
}