#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "nincompoop";

    //s1.erase(3, 2);
    //cout<<s1<<endl;

    //cout<<s1.find("poop")<<endl;
    //s1.insert(2, "lol");
   // cout<<s1<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.length()<<endl;

    for(int i=0; i<s1.length(); i++)
    {
        cout<<s1[i]<<endl;
    }
    return 0;
}