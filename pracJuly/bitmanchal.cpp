// bit manipulation challenges..//
#include <bits/stdc++.h>
using namespace std;

bool ispowerof2(int n)
{
    return (n && !(n & n-1));
}

int main()
{
    if(ispowerof2(228) == true){
        cout<<"It is a power of 2."<<endl;
    }
    else{
        cout<<"It is not a power of 2."<<endl;
    }
    return 0;
}