#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b){
    return a>b?a:b;
}

int getHeight(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct Node *createNode(int key)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return y;
}

struct Node *insert(struct Node *n, int key)
{
    if (n == NULL)
    {
        return (createNode(key));
    }
    if (key < n->key)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->key)
    {
        n->right = insert(n->right, key);
    }
    else
    {
        return n;
    }

    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    int bf = getBalanceFactor(n);

    // left-left case:
    if (bf > 1 && key < n->left->key)
    {
        return rightRotate(n);
    }
    // right-right case:
    if (bf < -1 && key > n->right->key)
    {
        return leftRotate(n);
    }
    // right-left case:
    if (bf < -1 && key < n->right->key)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    // left-right case:
    if (bf > 1 && key > n->left->key)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    return n;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}