#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxPathsumUtil(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = maxPathsumUtil(root->left, ans);
    int right = maxPathsumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right),
                      max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);

    int singlePathsum = max(root->data, max(root->data + left, root->data + right));
    return singlePathsum;
}

int maxPathsum(Node *root)
{
    int ans = INT_MIN;
    maxPathsumUtil(root, ans);

    return ans;
}

int32_t main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    // test
    cout << maxPathsum(root) << endl;
    return 0;
}