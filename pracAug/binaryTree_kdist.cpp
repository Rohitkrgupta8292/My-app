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

// case 1:
void printsubTree(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }
    printsubTree(root->left, k - 1);
    printsubTree(root->right, k - 1);
}

// case 2:
int printNodeAtk(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printsubTree(root, k);
        return 0;
    }
    int dl = printNodeAtk(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printsubTree(root->right, k - dl - 2);
        }
        return 1 + dl;
    }

    int dr = printNodeAtk(root->right, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printsubTree(root->left, k - dr - 2);
        }
        return 1 + dr;
    }

    return -1;
}

int32_t main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    printNodeAtk(root, root->left, 1);
    return 0;
}