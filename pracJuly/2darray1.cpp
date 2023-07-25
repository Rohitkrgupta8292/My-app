// searching element in the array...
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

    int x;
    cout<<"X: ";
    cin>>x;

    bool flag = false;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j] == x)
            {
                cout<<"Index:"<<i<<" "<<j<<endl;
                flag = true;
            }
        }
    }
    
    if(flag)
    {
        cout<<"Element Found!\n";
    }
    else
    {
        cout<<"Element Not Found!\n";
    }

    return 0;
}