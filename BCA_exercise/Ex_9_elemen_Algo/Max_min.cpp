// finding the maximum and minimum number in the array of integers..//
#include <bits/stdc++.h>
using namespace std;

void Max_Min(int a[], int n)
{
    int max, min;
    max = min = a[0];

    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
        if(min > a[i])
        {
            min = a[i];
        }
    }
    cout<<"Maximum number in array: "<<max<<endl;
    cout<<"Minimum number in array: "<<min;
}

int main()
{
    int n;
    cout<<"N: "; // size of array..//
    cin>>n;
    int A[n];
    cout<<"Enter the element of array: ";
    for(int i = 0; i<n; i++)
    {
        cin>>A[i];
    }
    Max_Min(A,n);
    return 0;
}