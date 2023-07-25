#include <bits/stdc++.h>
using namespace std;

bool sorted(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    bool restArray = sorted(arr + 1, n - 1);
    bool flag = arr[0] < arr[1] && restArray;
    
    return flag;
    
}

int main()
{
    int arr[] = {1, 5, 3, 4, 5};
    if (sorted(arr, 5))
    {
        cout << "The array is sorted\n";
    }
    else
    {
        cout << "The array is not sorted\n";
    }
    //cout << sorted(arr, 5) << endl;
    return 0;
}