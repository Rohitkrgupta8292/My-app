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

// check for bst..//
bool isBST(Node *root, Node *min=NULL, Node *max=NULL)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root-> data >= max->data)
    {
        return false;
    }
    bool leftvalid = isBST(root->left, min, root);
    bool rightvald = isBST(root->right, root, max);
    return leftvalid and rightvald;
}

int main()
{
    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->right->left = new Node(5);
    // root->right->right = new Node(6);
    // root->right->left->left = new Node(7);

    if(isBST(root, NULL, NULL)){
        cout<<"Valid BST\n";
    }
    else{
        cout<<"Invalid BST\n";
    }

    return 0;
}                           