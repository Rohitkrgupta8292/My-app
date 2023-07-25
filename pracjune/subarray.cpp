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

    int sum = 0;
    int count = 0;
    cout<<"Sum of indivisual arrays: ";
    for(int i=0;i<n;i++)
    {
        sum = 0;
        for(int j=i;j<n;j++)
        {
            sum += a[j];
            count += sum;
            cout<<sum<<" ";
        }
    }
    cout<<endl;
    cout<<"Sum of all Arrays: ";
    cout<<count<<endl;
    return 0;
}