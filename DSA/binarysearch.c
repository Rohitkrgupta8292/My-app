//binary search.
#include <stdio.h>

int binarySaarch(int a[], int n, int key)
{
    int s=0;
    int e=n;
    while(s<=e)
    {
        int mid =(s+e)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    return -1;
}

int main()
{   
    int a[] = {1,3,5,56,64,73,123,225,444};
    int size = sizeof(a)/sizeof(int);
    int key;
    printf("Enter  the element: ");
    scanf("%d", &key);
    int result = binarySaarch(a, size, key);
    if(result==-1)
    {
        printf("Element Not Found!\n");
    }
    else
    {
        printf("The element %d was found at index %d. \n",key, result);
    }
    return 0;
}