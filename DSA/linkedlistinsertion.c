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
// insertion at first..//
struct Node *insertionAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
// insertion in the middle of linked list..//
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
//insertion at the end of linked list..//
struct Node *insertAtEnd(struct Node*head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p =  head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
// insertion after the node..//
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

    printf("Elements in linked list before insertion:\n");
    linkedlistTraversal(head);
    //head = insertionAtFirst(head, 56);
    //head = insertAtIndex(head, 56,1);
    //printf("Elements in linked list after insertion:\n");
    //printf("Elements in linked list after insertion in the middile:\n");
    //head =  insertAtEnd(head, 45);
    head = insertAfterNode(third, head, 56);
    ///rintf("Elements in linked list after insertion at the end:\n");
    printf("Elements in linked list after insertion after the node:\n");
    linkedlistTraversal(head);
    return 0;
}