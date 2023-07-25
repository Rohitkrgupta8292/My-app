// converting infix expresion to postfix..//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack // creating structure of stack..//
{
    int size;
    int top;
    char *arr;
};
// checking stack is empty or not..//
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
// checking stack is full or not..//
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// pushing data to stack..//
void push(struct stack *ptr, char val)
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
// poping data to stack..//
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot Pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}


// giving the value at top in stack..//
int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}
// giving presendence to operator..//
int precendence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
// checking the array of charactor that is operator or not..//
int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;
    }
    else{
        return 0;
    }
 }
// converting to postfix..//
char *postfix(char *infix)
{
    struct stack *sp;  
    sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // track infix traversal..//
    int j = 0; // track postfix traversal..//
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precendence(infix[i]) > precendence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("Postfix is %s", postfix(infix));
    return 0;
}