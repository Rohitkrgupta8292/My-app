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

void display(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "NULL" << endl;
}

void insertAtfirst(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtend(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        insertAtfirst(head, val);
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deleteAthead(Node *&head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}

void deletion(Node *&head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    if (pos == 1)
    {
        deleteAthead(head);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main()
{
    Node *head = NULL;
    insertAtend(head, 1);
    insertAtend(head, 2);
    insertAtend(head, 3);
    insertAtend(head, 4);
    display(head);
    insertAtfirst(head, 5);
    display(head);
    deletion(head, 1);
    display(head);

    return 0;
}