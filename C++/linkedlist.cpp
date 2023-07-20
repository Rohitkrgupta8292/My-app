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

bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deletehead(Node *&head)
{
    Node *todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(Node *&head, int val)
{
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deletehead(head);
        return;
    }
    Node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    Node *todelelte = temp->next;
    temp->next = temp->next->next;

    delete todelelte;
}

int main()
{
    Node *head = NULL;
    insertAtend(head, 1);
    insertAtend(head, 2);
    insertAtend(head, 3);
    display(head);
    insertAtfirst(head, 4);
    display(head);
    //deletion(head, 3);
    deletehead(head);
    display(head);
    // int n;
    //  cout << "Enter the key: ";
    //  cin >> n;
    //  if (search(head, n) == false)
    //  {
    //      cout << "The key you are searching is not in linkedlist!\n";
    //  }
    //  else
    //  {
    //      cout << n << " is present in the linkedlist\n";
    //  }
    return 0;
}