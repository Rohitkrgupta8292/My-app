//finding out maximum and minimum numbers from arrays.
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;
    int a[n];
    for(int i=1; i<=n; i++)
    {
        cout<<"array "<<i<<":";
        cin>>a[i];
    }
    int maxNo=INT_MIN,minNo=INT_MAX;
    //int max=a[0], min=a[n-1];
    for(int i=1; i<=n;i++)
    {
        maxNo = max(maxNo,a[i]);
        minNo = min(minNo, a[i]);
    }
    cout<<"Max: "<<maxNo<<endl;
    cout<<"Min: "<<minNo<<endl;

    return 0;
}