// printing array..
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"N: ";
    cin>>n;
    cout<<"M: ";
    cin>>m;

    int arr[n][m];
    cout<<"Enter the value of Matrix\n";

    for(int i=0; i<n; i++)
    { 
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<"Matrix:\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}