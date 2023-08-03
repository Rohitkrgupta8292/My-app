// binary search challenge../
#include <bits/stdc++.h>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k)
{
    int pos = 0;
    int elements = 1;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largest_min_dist(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = -1;
    int left = 1;
    int right = n - 1;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 8, 4, 9};
    int n = 5;
    int k = 3;
    cout << "Largest min distance: " << largest_min_dist(arr, n, k);
    return 0;
}