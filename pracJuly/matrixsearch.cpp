// searching in the matrix..
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"N: ";
    cin>>n;
    cout<<"M: ";
    cin>>m;

    int target;
    cout<<"Target: ";
    cin>>target;

    cout<<"Enter the element of matrx:\n";
    int mat[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>mat[i][j];
        }
    }

    bool flag = false;
    int r = 0, c = m-1;
    while(r<n && c>=0)
    {
        if(mat[r][c] == target)
        {
            flag = true;
        }
        if(mat[r][c]> target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    if(flag)
    {
        cout<<"Element found!\n";
    }
    else
    {
        cout<<"Element doestn't exist!\n";
    }

    return 0;
}