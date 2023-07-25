#include <stdio.h>
#include <stdlib.h>
// creating structure of Node..//
struct Node
{
    int data;
    struct Node *next;
};
// Traversal of circular linked list..//
void linkedlistTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
};
// insertion at the first of circular linked list..//
struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node *p = head->next;
    while(p->next != head){
        p = p->next;
    }
    // At this point p point to the last node of this circular list..//
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
// insertion at the index or middle of circular linked list..//
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int i = 0;
    while(i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    ptr->data = data;
    ptr->next = temp->next;
    temp->next = ptr;
    return head;
}
// insertion at the end of circular linked list..//
struct Node *insertAtEnd(struct Node*head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p =  head;

    while(p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

// insertion after the node in circular linked list..//
struct Node *insertAfterNode(struct Node*prevNode,struct Node*head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p =  head;
    
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
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
    head->data = 4;
    head->next = second;
    // link second and third nodes..
    second->data = 3;
    second->next = third;
    // link third and fourth nodes of list nodes..
    third->data = 6;
    third->next = fourth;
    // terminate fourth nodes..
    fourth->data = 1;
    fourth->next = head;

    printf("Elements in circular linked list before insertion:\n");
    linkedlistTraversal(head);
    //head = insertAtFirst(head, 56);
    //printf("Elements in circular linked list after insertion at first:\n");
    //head = insertAtIndex(head, 56,1);
    //printf("Elements in linked list after insertion in the middile:\n");
    //head =  insertAtEnd(head, 45);
    //printf("Elements in circular linked list after insertion at the end:\n");
    head = insertAfterNode(fourth, head, 56);
    printf("Elements in circular linked list after insertion after the node:\n");
    linkedlistTraversal(head);
    return 0;
}