#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int maximum(int *a, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

void countSort(int *a, int n)
{
    int i, j;
    // find the maximum element in array a..//
    int max = maximum(a, n);
    // creating count array..//
    int *count = (int *)malloc((max + 1) * sizeof(int));
    // initialize the array element to zero../
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }
    // incrementing the corresponding index in the count array..//
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    i = 0; // counter for count array..//
    j = 0; // counter for given array..//
    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] -= 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int a[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(a, n);
    printf("Running Count Sort...\n");
    countSort(a, n);
    printArray(a, n);
    return 0;
}