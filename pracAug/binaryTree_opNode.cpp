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
// Number of NOde .. in binary tree.//
int countNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNode(root->left) + countNode(root->right) + 1;
}
// sum of Nodes..//
int sumNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sumNode(root->left) + sumNode(root->right) + root->data;
}

int calcHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    return max(lHeight, rHeight) + 1;
}
// calculating optimised verrsion of diameter of binary tree..//
int calcDiam(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = calcDiam(root->left, &lh);
    int rDiameter = calcDiam(root->right, &rh);
    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currDiameter, max(lDiameter, rDiameter));
}

// calculating diameter of binary tree..//
int calcDiameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}

int32_t main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Number of Node: " << countNode(root) << "\n"; // giving no of node in calc tree..//
    cout << "Sum of Node:" << sumNode(root) << "\n";  // giving the sum of all naode in< calc tree../
    cout << "Height: " << calcHeight(root) << endl;        // giving the height of binary tree..//

    cout << "Diameter: " << calcDiameter(root) << endl;
    int height = 0;
    cout << "Diameter: " << calcDiam(root, &height) << endl;
    return 0;
}