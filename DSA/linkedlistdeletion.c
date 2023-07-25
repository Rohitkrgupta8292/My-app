#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// traversal of linked list..//
void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
// deleting the first element from the node..//
struct Node *deleteFirst(struct Node *head)
{ 
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}   
// deleting the element at the given index from the linked list..//
struct Node *deleteAtIndex(struct Node*head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while(i < index-1){
        p = p->next;
        q = q->next;
        i++;
    }   
    p->next = q->next;
    free(q);
    return head;
}

// deleting the last node of given linked list.../
struct Node *deleteLast(struct Node *head)
{ 
   struct Node * p =  head;
   struct Node * q = p->next;

    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}  

// deleting the given node from linked list..//
struct Node *deleteAfterNode(struct Node*head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while(q->data!=value && q->next != NULL){
        p = p->next;
        q = q->next;
    }   
    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
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
    third->data = 8;
    third->next = fourth;
    // terminate fourth nodes..
    fourth->data = 1;
    fourth->next = NULL;

    printf("Elements in linked list before deletion:\n");
    linkedlistTraversal(head);

    //head = deleteFirst(head); // for deleting element from first of linked list..//
    //printf("Elements in linked list after deletion at the end:\n");
    //head = deleteAtIndex(head, 2);
    //printf("Elements in linked list after deletion at the index:\n");
    //printf("Elements in linked list after deletion at the end:\n");
    //head = deleteLast(head);
    printf("Elements in linked list after deletion after a node:\n");
    head = deleteAfterNode(head, 1);
    linkedlistTraversal(head);
    return 0;
} 