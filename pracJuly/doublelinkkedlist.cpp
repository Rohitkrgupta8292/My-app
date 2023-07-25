// Double linkedlist..//
#include <bits/stdc++.h>
using namespace std;
// creatation of Doubly linkedlist..//
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deletion(Node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    if (head != NULL)
    {
        head->prev = temp;
    }
    head = temp;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtend(Node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    Node *n = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

int lenght(Node *head)
{
    int l = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

Node *kappend(Node *&head, int k)
{
    Node *newhead;
    Node *newtail;
    Node *tail = head;

    int l = lenght(head);
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newtail = tail;
        }
        if (count == l - k + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}

int main()
{
    Node *head = NULL;
    insertAtend(head, 1);
    insertAtend(head, 2);
    insertAtend(head, 3);
    insertAtend(head, 4);
     //display(head);
    insertAtend(head, 5);
    insertAtend(head, 6);
    display(head);
    Node*newhead = kappend(head, 3);
    display(newhead);
    //deletion(head, 1);
    return 0;
}