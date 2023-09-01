//binary search.
#include <iostream>
using namespace std;

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
    int n;
    cout<<"N: ";
    cin>>n;

    int a[n];
        for(int i=0; i<n; i++)
    {
        int array = 0;
        array = i + 1;
        cout<<"array "<<array<<":";
        cin >> a[i];
    }
    int key;
    cout<<"Key: ";
    cin>>key;
    int result = binarySaarch(a, n, key);
    if(result==-1)
    {
        cout<<"Not found\n";
    }
    else
    {
        cout<<"Found at index "<<result<<endl;
    }

    return 0;
}