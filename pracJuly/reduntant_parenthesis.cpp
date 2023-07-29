#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Input: ";
    cin >> s;

    stack<char> st;
    bool ans = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                ans = true;
            }
            while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
            {
                st.pop();
            }
            st.pop();
        }
    }
    //cout << ans;
    if (ans)
    {
        cout << s << " has reduntant parenthesis\n";
    }
    else
    {
        cout << s << " has not a reduntant parenthesis\n";
    }
    return 0;
}