#include <iostream>
using namespace std;

int main()
{
    int mx = -19999999;
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
        if(a[i] < mx)
        {
            cout<<"Array must be greater than -19999999\n";
            return 1;
        }
    }
    cout<<"sequence: ";
    //int max;
    for(int i=0; i<n; i++)
    {
        mx = max(mx, a[i]);
        cout<<mx<<" ";
    }
    cout<<endl;
    return 0;
}