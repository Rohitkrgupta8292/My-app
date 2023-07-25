#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void increment(int *c)
{
    *c++;
}

int main()
{
    int a=2;
    int b=4;

    // passing by refrence..//
    int *aptr = &a;
    int *bptr = &b;
    
    swap(aptr,bptr);
    cout<<a<<" "<<b<<endl;

    int c = 5;
    int *cptr = &c;
    increment(cptr);
    cout<<c<<endl;

}