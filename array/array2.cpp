#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;
    int array[n];
    
    //cout<<"array: ";

    for(int i=1;i<=n;i++)
    {
        cout<<"array "<<i<<":";
        cin>>array[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}