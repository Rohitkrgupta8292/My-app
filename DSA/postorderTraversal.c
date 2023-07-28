#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer..//
    n = (struct node *)malloc(sizeof(struct node)); // allocating memory in the heap..//
    n->data = data;                                 // setting the data..//
    n->left = NULL;                                 // setting the left children to NULL..//
    n->right = NULL;                                // setting the right children to NULL..//
    return n;                                       // returning the node..//
}
// function to print binary tree in postorder..//
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    // constructing the root node..//
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    // visually the tree look like..//
    //     4
    //    / \  
   //   1   6
    //  / \ 
   // 5   2

    // linking the root node with left and right children..//
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    postOrder(p);
    return 0;
}