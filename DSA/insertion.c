#include <stdio.h>
void display(int arr[], int n);
int indInsertion(int arr[], int size, int element, int index, int capacity);
int main()
{
   int arr[100] = {7, 8, 12, 27, 88};
   int size = 5, element, index;
   printf("Enter the element you want to add in array: ");
   scanf("%d", &element);
   printf("Enter the index: ");
   scanf("%d", &index);
   printf("Before insertion: ");
   display(arr, size);
   if(index <= size)
   {
       printf("Insertion successful!\n");
       printf("After insertion:  ");
       indInsertion(arr, size, element, index, 100);
        size += 1;
       display(arr, size);
   }
   else
   {
      printf("Insertion failed\n");
   }
   return 0;
}

// traversal to all array..
void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// code for insertion//
int indInsertion(int arr[], int size, int element, int index, int capacity)
{
    if((size>=capacity))
    {
        return -1;
    }
    else
    {
        for(int i = size-1; i >= index; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[index] = element;
        return 1;
    }
}