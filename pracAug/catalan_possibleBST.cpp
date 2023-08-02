#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<Node *> constructTree(int start, int end)
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftsubtree = constructTree(start, i - 1);
        vector<Node *> rightsubtree = constructTree(i + 1, end);

        for (int j = 0; j < leftsubtree.size(); j++)
        {
            Node *left = leftsubtree[j];
            for (int k = 0; k < rightsubtree.size(); k++)
            {
                Node *right = rightsubtree[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    vector<Node *> totalTree = constructTree(1, 3);
    for (int i = 0; i < totalTree.size(); i++)
    {
        cout << (i + 1) << " : ";
        preOrder(totalTree[i]);
        cout << endl;
    }
    return 0;
}