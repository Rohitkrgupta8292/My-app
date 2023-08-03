#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << s.size() << endl;
    s.erase(s.find(3));
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}