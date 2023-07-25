// using compare function to compare two strings..//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "abc";
    string s2 = "abc";
    if (!s1.compare(s2))
    {
        cout << "The string is same";
    }
    else{
        cout << "The string is not same";
    }
    return 0;
}