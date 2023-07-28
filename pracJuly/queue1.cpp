// queue implementation using linked list..//
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

class Queue
{
    Node *front;
    Node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(int x)
    {
        Node *n = new Node(x);
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
        if (front == NULL)
        {
            front = front->next;
        }
    }

    void dequeue()
    {
        if (empty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        Node *todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek()
    {
        if (empty())
        {
            cout << "No element in queue to show!\n";
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }

    void display()
    {
        if (empty())
        {
            cout << "No element in the queue to print!\n";
            return;
        }
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    cout<<q.peek()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.peek()<<endl;
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<q.peek()<<endl;
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<q.peek()<<endl;
    cout<<q.empty()<<endl;;

    return 0;
}