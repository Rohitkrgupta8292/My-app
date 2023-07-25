// linear search.
#include <stdio.h>

int linearSearch(int a[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,3,5,56,4,3,23,5,4,54634,54,34};
    int size = sizeof(arr)/sizeof(int);
    int key = 34;
    int search = linearSearch(arr, size, key);  
    if(search == -1)
    {
        printf("Element Not found in array!\n");
    }
    else
    {
        printf("The element %d was found at index %d. \n", key, search);
    }
    return 0;
}