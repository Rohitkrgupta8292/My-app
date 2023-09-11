// Digital dictionary using tries..//
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *next[26];
    bool end;
    node()
    {
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
        end = false;
    }
};
class Trie
{
private:
    node *root;

public:
    Trie()
    {
        root = new node();
    }
    void insert(string s)
    {
        node *it = root;
        for (auto c : s)
        {
            if (!it->next[c - 'a'])
            {
                it->next[c - 'a'] = new node();
            }
            it = it->next[c - 'a'];
        }
        it->end = true;
    }

    void find(string s)
    {
        node *it = root;
        for (char ch : s)
        {
            if (!it->next[ch - 'a'])
            {
                cout << "No suggestion\n";
                insert(s);
                return;
            }
            it = it->next[ch - 'a'];
        }
        vector<string> res;
        printall(it, s, res, "");
        for (auto c : res)
        {
            cout << s << c << "\n";
        }
    }
    void printall(node *it, string &s, vector<string> &res, string cur)
    {
        if (it == NULL)
        {
            return;
        }
        if (it->end)
        {
            res.push_back(cur);
        }
        for (int i = 0; i < 26; i++)
        {
            if (it->next[i])
            {
                printall(it->next[i], s, res, cur + char('a' + i));
            }
        }
    }
};

int main()
{
    Trie t;
    int n;
    cout << "N: ";
    cin >> n;
    vector<string> a(n);
    for (auto &i : a)
    {
        cout<<"s: ";
        cin >> i;
        t.insert(i);
    }
    int q;
    cout << "Q: ";
    cin >> q;
    while (q--)
    {
        string s;
        cout << "s: ";
        cin >> s;
        t.find(s);
    }
    return 0;
}