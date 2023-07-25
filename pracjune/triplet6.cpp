#include <iostream>
using namespace std;

bool check(int x, int y, int z)
{
     int a = max(x, max(y,z));
     int b,c;

     if(a == x)
     {
        b = y;
        c = z;
     }
     else if(a == y)
     {
        b = x;
        c = z;
     }
     else
     {
        b = x;
        c = z;
     }

     if(a*a == (b*b + c*c))
     {
        return true;
     }
     else
     {
        return false;
     }
}

int32_t main()
{
    int x,y,z;
    cout<<"X: ";
    cin>>x;
    cout<<"Y: ";
    cin>>y;
    cout<<"Z: ";
    cin>>z;

    if(check(x,y,z))
    {
        cout<<"PYTHAGOREAN TRIPLET\n";
    }
    else
    {
        cout<<"NOT A PYTHAGOREAN TRIPLET\n";
    }
    return 0;
}