#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;

    do
    {
        cout<<n<<endl;
        cout<<"N: ";
        cin>>n;
    } while(n>0);

    return 0;   
}