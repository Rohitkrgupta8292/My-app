#include <stdio.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int *a, int l, int h)
{
    int pivot = a[l];
    int i = (l + 1);
    int j = h;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int *a, int l, int h)
{
    if (l < h)
    {
        int p = partition(a, l, h);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, h);
    }
}

int main()
{
    int a[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int n = 9;
    printArray(a, n);
    printf("Running Quick Sort...\n");
    quickSort(a, 0, n-1);
    printArray(a, n);
    return 0;
}