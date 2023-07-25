// changing string of word where Pi is present change to 3.14 value..//
#include <bits/stdc++.h>
using namespace std;

void replacePi(string s)
{ // pippppiiiipi  //
    if (s.length() == 0)
    {
        return; // base case//
    }

    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacePi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacePi(s.substr(1));
    }
}

int main()
{
    replacePi("pippppiiiipi");
    cout<<endl;
    return 0;
}