#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "fajdfgmdfgkregegbk";

    int count[26];
    for(int i=0; i<26; i++)
    {
        count[i] = 0;
    }
    for(int i=0; i<s.length(); i++)
    {
        count[s[i] -'a']++;
    }

    char ans = 'a';
    int max = 0;

    for(int i = 0; i<26; i++)
    {
        if(count[i] > max)
        {
            max = count[i];
            ans = i + 'a';
        }
    }

    cout<<max<<" "<<ans<<endl;
    return 0;
}