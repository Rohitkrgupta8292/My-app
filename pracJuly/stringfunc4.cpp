#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "nincompoop";

    string s = s1.substr(6,4 );
    cout<<s<<endl;

    string s2 = "786";
    int n = stoi(s2);
    cout<<n<<endl;
    cout<<n+2<<endl;

    int x = 786;
    cout<<to_string(x) + "2"<<endl;
    return 0;
}