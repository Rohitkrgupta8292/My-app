//bubble sorting.
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;

    int a[n];
    
    for(int i=0; i<n;i++)
    {
        int array = 0;
        array = i + 1;
        cout<<"array "<<array<<":";
        cin >> a[i];
    }

    int counter = 1;
    while(counter < n)
    {
        for(int i=0; i<n-counter; i++)
        {
            if(a[i] > a[i+1])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
        counter++;
    }
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}