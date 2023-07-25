#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int r;
    int f;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("circularQueue is full!\n");
    }
    else
    {
        printf("Enqued element: %d\n", val);
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("circularQueue is Empty!\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct circularQueue q;
    q.size = 4;
    q.r = 0;
    q.f = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // EncircularQueue few elements../
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    enqueue(&q, 45);
    enqueue(&q, 43);
    enqueue(&q, 42);

    if (isEmpty(&q))
    {
        printf("circularQueue is Empty!\n");
    }

    if (isFull(&q))
    {
        printf("circularQueue is full!\n");
    }
    return 0;
}