#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // allocation of memory in the heap (dynaminc memory allocation)//
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes..
    head->data = 7;
    head->next = second;
    // link second and third nodes..
    second->data = 11;
    second->next = third;
    // link third and fourth nodes of list nodes..
    third->data = 66;
    third->next = fourth;
    // terminate fourth nodes..
    fourth->data = 104;
    fourth->next = NULL;

    linkedlistTraversal(head);
    return 0;
}