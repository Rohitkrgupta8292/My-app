#include <bits/stdc++.h>
using namespace std;

// define int long long..//
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

struct Node
{
    int key;
    Node *left, *right;

public:
    Node(int val)
    {
        key = val;
        left = right = NULL;
    }
};

void getVerticalOrder(Node *root, int hd, map<int, vi> &m)
{
    if (root == NULL)
    {
        return;
    }
    m[hd].push_back(root->key);
    getVerticalOrder(root->left, hd - 1, m);
    getVerticalOrder(root->right, hd + 1, m);
}

signed main()
{
    Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    map<int, vector<int>> m;
    int hd = 0;

    getVerticalOrder(root, hd, m);

    map<int, vi>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < (it->ss).size(); i++)
        {
            cout << (it->ss)[i] << " ";
        }
        cout << endl;
    }
    return 0;
}