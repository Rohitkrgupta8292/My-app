#include <bits/stdc++.h>
using namespace std;

void permutation(string s, string ans){
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        string temp = s.substr(0, i) + s.substr(i+1, s.length()-1);
        permutation(temp, ans+ch);
    }
}

int main()
{
    permutation("ABC", "");
    cout<<endl;
    return 0;
}