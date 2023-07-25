#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " "; // 1 2 3
    }
    cout << endl;

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " "; // 1 2 3
    }
    cout << endl;

    for (auto element : v)
    {
        cout << element << " "; // 1 2 3
    }
    cout << endl;

    v.pop_back();
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(2);
    v2.push_back(1);

    for (auto element : v2)
    {
        cout << element << " ";
    }
    cout << endl;

    swap(v, v2);

    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;

    for (auto element : v2)
    {
        cout << element << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout<<endl;

    return 0;
}