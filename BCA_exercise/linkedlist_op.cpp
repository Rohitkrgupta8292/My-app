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
    Node *ptr = new Node(val);
    if (head == NULL)
    {
        insertAtfirst(head, val);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}

void insertAfterNode(Node *&head, Node *&prev, int val)
{
    if (head == NULL)
    {
        insertAtfirst(head, val);
    }
    Node *n = new Node(val);
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == prev->data)
        {
            n->next = prev->next;
            prev->next = n;
            return;
        }
        temp = temp->next;
    }

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

void deleteHead(Node *&head){
    if(head == NULL){
        return;
    }
    Node* todelte = head;
    head = head->next;
    delete todelte;
}

void deletion(Node *&head, int val){
    if(head== NULL){
        return;
    }
    if(head ->next == NULL){
        deleteHead(head);
    }

    Node * temp = head;
    while(temp->next->data != val){
        temp= temp->next ;
    }
    Node *todelete = temp->next;
    temp->next = temp->next-> next;
    delete todelete;
}


int main()
{
    Node *head = NULL;
    insertAtend(head, 1);
    insertAtend(head, 2);
    insertAtfirst(head, 3);
    insertAtend(head, 5);
    insertAfterNode(head, head->next->next->next, 8);
    insertAfterNode(head, head->next->next->next, 7);
    deleteHead(head);
    deletion(head, 5);

    display(head);
    return 0;
}