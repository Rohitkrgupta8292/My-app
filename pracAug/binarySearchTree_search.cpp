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

// Node *searchInBST(Node *root, int key)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     if (root->data == key)
//     {
//         return root;
//     }
//     if (root->data > key)
//     {
//         return searchInBST(root->left, key);
//     }
//     return searchInBST(root->right, key);
// }

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

// delete in BST../
Node *deleteInBST(Node *root, int key)
{
    if (root->data > key)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // case 3:
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    inOrder(root);
    cout<<endl;
    root = deleteInBST(root, 2);
    inOrder(root);

    return 0;
}