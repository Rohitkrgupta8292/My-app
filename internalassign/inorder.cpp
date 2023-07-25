#include <iostream>
using namespace std;

// Structure for a binary tree node
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }

};

// Function to perform inorder traversal of a binary tree
void inorderTraversal(Node* root)
{
    if (root == NULL)
    return;

    // Visit left subtree
    inorderTraversal(root->left);

    // Print current node's data
    cout << root->data << " ";

    // Visit right subtree
    inorderTraversal(root->right);
}

int main()
{
    // Create the binary tree
    Node*root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);

    // Perform inorder traversal.
    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl;
    return 0;
}