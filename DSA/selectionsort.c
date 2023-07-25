#include <stdio.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selectionSort(int *a, int n)
{
    printf("Running selection Sort!\n");
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    int a[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    int n = 11;
    printArray(a, n);
    selectionSort(a, n);
    printArray(a, n);
    return 0;
}