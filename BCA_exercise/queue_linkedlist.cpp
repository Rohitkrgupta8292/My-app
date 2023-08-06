// queue implement using linked list..//
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
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x)
    {
        Node *n = new Node(x);
        if (empty())
        {
            rear = n;
            front = n;
            cout << "enqueue element: " << x << endl;
            return;
        }
        rear->next = n;
        rear = n;
        cout << "enqueue element: " << x << endl;
    }

    bool empty()
    {
        return front == NULL;
    }

    void dequeue()
    {
        if (empty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        Node *todelete = front;
        int d = front->data;
        front = front->next;
        cout << "dequeued element: " << d << endl;
        delete todelete;
    }

    void display()
    {
        if (empty())
        {
            cout << "No element to print!\n";
            return;
        }
        Node *temp = front;
        cout<<"Queue: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printDequeue()
    {
        if (empty())
        {
            cout << "No element in queue to dequeue!\n";
            return;
        }
        while (!empty())
        {
            dequeue();
        }
    }
};

int main()
{
    Queue q;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        q.enqueue(arr[i]);
    }
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.printDequeue();
    q.display();
    q.dequeue();
    return 0;
}