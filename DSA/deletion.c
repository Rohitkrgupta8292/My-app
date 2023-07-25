#include <stdio.h>
void display(int arr[], int n);
void indDeletion(int arr[], int size, int inde);
int main()
{
   int arr[100] = {7, 8, 12, 27, 88, 23};
   int size = 6, index;
   printf("Enter the index: ");
   scanf("%d", &index);
   printf("Before deletion: ");
   display(arr, size);
   if(index < size)
   {
       printf("Deletion successful!\n");
       printf("After deletion:  ");
       indDeletion(arr, size, index);
       size -= 1;
       display(arr, size);
   }
   else
   {
      printf("Deletion failed\n");
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
// code for deletion//
void indDeletion(int arr[], int size, int index)
{

   for(int i = index; i < size; i++)
    {
        arr[i] = arr[i+1];
    } 
}