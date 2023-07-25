// reversing string using recursion function..//
#include <bits/stdc++.h>
using namespace std;

void reverse(string s){
    if(s.length()==0){ // base case
        return;
    }
    reverse(s.substr(1));
    cout<<s[0];
}

int main()
{
    reverse("Malayalam");
    cout<<endl;

    return 0;
}