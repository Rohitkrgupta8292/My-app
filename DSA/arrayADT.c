// Abstract Data Types..
#include <stdio.h>
#include <stdlib.h>

struct myArray
{
   int total_size;
   int used_size;
   int *array;
};

void createArray(struct myArray * a, int tSize, int uSize)
{
    //(*a).total_size = tSize;
    //(*a).used_size = uSize;
    //(*a).array = (int *) malloc(tSize*sizeof(int));
    a->total_size = tSize;
    a->used_size = uSize;
    a->array = (int *) malloc(tSize*sizeof(int));
}

void show(struct myArray *a)
{
    for(int i=0; i < a->used_size; i++)
    {
        printf("%d\n",(a->array)[i]);
    }
}

void setVal(struct myArray *a)
{
    for(int i=0; i < a->used_size; i++)
    {
        int n;
        printf("Enter Element %d:",i);
        scanf("%d",&n);
        (a->array)[i] = n;
    }
}

int main()
{ 
    struct myArray marks;
    createArray(&marks, 10, 2);
    printf("We are running setVal now\n");
    setVal(&marks);
    printf("We are running show now\n");
    show(&marks);

    return 0;
}