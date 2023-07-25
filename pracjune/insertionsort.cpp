//insertion sorting.
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        int array = 0;
        array = i + 1;
        cout<<"array "<<array<<":";
        cin >> a[i];
    }

    for(int i=1;i<n;i++)
    {
        int currentNo = a[i];
        int previousNo = i-1;
        while(a[previousNo]>currentNo && previousNo>=0)
        {
            a[previousNo+1]=a[previousNo];
            previousNo--;
        }
        a[previousNo+1]=currentNo;
    }

    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}