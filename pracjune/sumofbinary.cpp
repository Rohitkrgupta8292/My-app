// sum of two binary.
#include <iostream>
using namespace std;

int reverse(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int lastdigit = n%10;
        sum = sum*10 + lastdigit;
        n = n/10;
    }
    return sum;
}

int addBinary(int a, int b)
{
    int sum = 0;
    int prevcarry = 0;
    while (a > 0 && b > 0)
    {
        if(a%2 == 0 && b%2 == 0)
        {
            sum = sum*10 + prevcarry;
            prevcarry = 0;
        }
        else if((a%2 == 0 && b%2 == 1) || (a%2 == 1 && b%2 == 0) )
        {
            if(prevcarry == 1)
            {
                sum = sum*10 + 0;
                prevcarry = 1;
            }
            else
            {
                sum = sum*10 + 1;
                prevcarry = 0;
            }
        }
        else
        {
            sum = sum*10 + prevcarry;
            prevcarry = 1;
        }
        a = a/10;
        b = b/10;
    }
    while (a > 0)
    {
        if(prevcarry == 1)
        {
            if (a%2 == 1)
            {   
            sum = sum*10 + 0;
            prevcarry = 1;
            }
            else
            {
                sum = sum*10 + 1;
                prevcarry = 1;
            }
        }
        else
        {
            sum = sum*10 + (a%2);
        }
        a = a/10;
     
    }
    
    while (b > 0)
    {
        if(prevcarry == 1)
        {
            if (b%2 == 1)
            {   
            sum = sum*10 + 0;
            prevcarry = 1;
            }
            else
            {
                sum = sum*10 + 1;
                prevcarry = 1;
            }
        }
        else
        {
            sum = sum*10 + (b%2);
        }
        b = b/10; 
    }

    if(prevcarry == 1)
    {
        sum = sum*10 + 1;
    }
    sum = reverse(sum);
    return sum;
}

int main()
{
    int a,b;
    cout<<"A: ";
    cin>>a;
    cout<<"B: ";
    cin>>b;

    cout<<addBinary(a,b) <<endl;
    return 0;
}