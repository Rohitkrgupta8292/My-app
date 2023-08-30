// linear search.
#include <iostream>
using namespace std;

int linearSeach(int a[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"N: ";
    cin >> n;
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
    cin >> key;
    int index = linearSeach(a, n, key);
    if(index == -1)
    {
        cout<<"Not found\n";
    }
    else
    {
        cout<<index<<endl;
    }
    return 0;
}