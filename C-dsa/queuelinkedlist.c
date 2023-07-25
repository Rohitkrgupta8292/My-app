#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is Full!\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val= -1;
    struct Node *n = f;
    if (f == NULL)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
       f= f->next;
       val = n->data;
       free(n);
    }
    return val;
}

int main()
{
    //display(f);
   // printf("Dequeued: %d\n", dequeue());
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display(f);
    printf("Dequeued: %d\n", dequeue());
    display(f);
    return 0;
}