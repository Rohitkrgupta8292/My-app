#include <bits/stdc++.h>
using namespace std;

int first(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return first(arr, n, i + 1, key);
}

int last(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int restArray = last(arr, n, i + 1, key);
    if (restArray != -1)
    {
        return restArray;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}

int main()
{
    int arr[] = {4, 2, 1, 2, 5, 2, 7};
    cout << first(arr, 7, 0, 2) << endl;
    cout << last(arr, 7, 0, 2) << endl;
    return 0;
}