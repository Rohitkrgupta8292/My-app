#include<iostream>
using namespace std;

int main()
{
    int a,b,c;

    cout<<"a:";
    cin>>a;

    cout<<"b:";
    cin>>b;

    cout<<"c:";
    cin>>c;

    if (a>b)
    {
        if (a>c)
        {

            cout<<"a is greatest:"<<a; 
        }
        else
        {
            cout<<"c is greatest:"<<c;
        }
    }
    else
    {
        if (b>c)
        {
            cout<<"b is greatest:"<<b;
        }
        else
        {
            cout<<"c is greatest:"<<c;
        }
    }
    cout<<endl;

    return 0;
}