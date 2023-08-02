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

Node *constructBst(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    if(*preorderIdx >= n){
        return NULL;
    }

    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIdx += 1;

        if (*preorderIdx < n)
        {
            root->left = constructBst(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if (*preorderIdx < n)
        {
            root->right = constructBst(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }

    return root;
}

void preOrder(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx  = 0;
    Node* root = constructBst(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, 5);
    preOrder(root);
    return 0;
}