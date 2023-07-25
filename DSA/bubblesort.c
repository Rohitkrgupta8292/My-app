#include <stdio.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSortAdaptive(int *a, int n)
{
    int sorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Working on pass number %d\n", i + 1);
        sorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                sorted = 0;
            }
        }
        if (sorted)
        {
            return;
        }
    }
}

void bubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("Working on pass number %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    //int a[] = {1, 2, 3, 4, 5, 6};
    int n = 11;
    printArray(a, n); // printing the array..//
    bubbleSortAdaptive(a, n); // bubble sort adaptive..//
    printArray(a, n); // printing the sorting array..//
    bubbleSort(a, n); // bubble sort..//
    printArray(a, n); // printing sorted array..//
    return 0;
}