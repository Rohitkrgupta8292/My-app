#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *tp)
{
    if (tp == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *tp)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *tp, int x)
{
    if (isFull(tp))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = tp;
        top = n;
        return top;
    }
}

int pop(struct Node *tp)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        struct Node *n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int stackTop(struct Node *tp)
{
    return tp->data;
}

int stackBottom(struct Node *tp)
{
    struct Node *ptr = tp;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 15);
    // linkedlistTraversal(top);
    // printf("Popped Element is %d\n", pop(top));
    // printf("Popped Element is %d\n", pop(top));
    linkedlistTraversal(top);
    // printf("Value at Postion 1 is %d\n",peek(1));
    for (int i = 1; i <= 4; i++)
    {
        printf("Value at Postion %d is %d\n", i, peek(i));
    }

    printf("The value at top of stack: %d\n", stackTop(top));
    printf("The value at bottom of stack: %d\n", stackBottom(top));
    return 0;
}