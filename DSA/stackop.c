#include <stdio.h>
#include <stdlib.h>
// structure of stack ..//
struct stack
{
    int top;
    int size;
    int *arr;
};
// checking stack underflow..//
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// checking the stack overflow..//
int isFull(struct stack *ptr)
{
    if ((ptr->top) == (ptr->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// push/insertion in stack..//
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot Push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
// pop/deletion from stack..//
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot Pop from the stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
// printing particular value from stack..//
int peek(struct stack *ptr, int i)
{
    int arrayInd = ptr->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid a position\n");
        return -1;
    }
    else
        ;
    {
        return ptr->arr[arrayInd];
    }
}
// giving the value at top in stack..//
int stackTop(struct stack * sp){
    return sp->arr[sp->top];
}
// giving the value at bottom in stack..//
int stackBottom(struct stack * sp){
    return sp->arr[0];
}

int main()
{
    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 10;
    sp->arr = (int *)malloc(sizeof(int) * sp->size);
    printf("Stack is created successfully!\n"); // stack created successfully..//

    printf("Before Pushing, Full: %d\n", isFull(sp));
    printf("Before Pushing, Empty: %d\n", isEmpty(sp));
    // Pushing  to the stack..///
    push(sp, 56);
    push(sp, 15);
    push(sp, 54);
    push(sp, 12);
    push(sp, 11);
    push(sp, 6);
    push(sp, 5);
    push(sp, 23);
    push(sp, 33);
    push(sp, 43); // ---> Pushed 10 values..//
                  // push(sp, 34); // stack overflow..//

    printf("After Pushing, Full: %d\n", isFull(sp));
    printf("After Pushing, Emplty: %d\n", isEmpty(sp));
    // Popping from the stack..//
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    // printing values inside the stack..//
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp,j));
    }

    printf("The value at top of stack: %d\n",stackTop(sp));
    printf("The value at bottom of stack: %d\n", stackBottom(sp));
    return 0;
}