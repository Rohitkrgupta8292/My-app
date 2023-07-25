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
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
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

Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

Node *reverseRecursive(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

Node *reversek(Node *&head, int k)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reversek(next, k);
    }
    return prev;
}

void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

int main()
{
    Node *head = NULL;
    insertAtend(head, 1);
    insertAtend(head, 2);
    insertAtend(head, 3);
    insertAtend(head, 4);
    insertAtend(head, 5);
    insertAtend(head, 6);
    makeCycle(head, 3);
    cout << detectCycle(head) << endl;
    removeCycle(head);
    cout << detectCycle(head) << endl;
    display(head);
    
    //  insertAtfirst(head, 4);
    //  display(head);
    //  deletion(head, 3);
    //  deletehead(head);
    //  display(head);
    //  reverse(head);
    //  Node *newhead = reverseRecursive(head);
    //  display(newhead);

    // int k = 2;
    // Node *newhead = reversek(head, k);
    // display(newhead);
    return 0;
}