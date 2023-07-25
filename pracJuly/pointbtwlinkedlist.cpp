// finding the intersection point between two linked list..//
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtfirst(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}

void insertAtend(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int lenght(Node *head)
{
    int l = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

int intersection(Node *&head1, Node *&head2)
{
    int l1 = lenght(head1);
    int l2 = lenght(head2);
    int d = 0;
    Node *ptr1;
    Node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void intersect(Node *&head1, Node *&head2, int pos)
{
    Node *temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int main()
{

    Node *head1 = NULL;
    Node *head2 = NULL;
    insertAtend(head1, 1);
    insertAtend(head1, 2);
    insertAtend(head1, 3);
    insertAtend(head1, 4);
    insertAtend(head1, 5);
    insertAtend(head1, 6);
    insertAtend(head2, 9);
    insertAtend(head2, 10);
    intersect(head1, head2, 3);
    display(head1);
    display(head2);
    cout<<"Intersection point: "<<intersection(head1,head2)<<endl;
    return 0;
}