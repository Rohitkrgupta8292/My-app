// queue implementation using array..//
#include <bits/stdc++.h>
using namespace std;

#define n 100

class Queue
{
    int *arr;
    int front;
    int rear;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if (rear == n - 1)
        {
            cout << "Queue overflown!\n";
            return;
        }
        rear++;
        arr[rear] = x;
        cout << "enqueued element: " << x << endl;
        if (front == -1)
        {
            front++;
        }
    }

    bool empty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        return false;
    }

    void dequeue()
    {
        if (empty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        int d = arr[front];
        cout << "dequeued element: " << d << endl;
        front++;
    }

    void display()
    {
        if (empty())
        {
            cout << "No element in the queue to print!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void printdequeue()
    {
        if (empty())
        {
            cout << "No element to dequeue!\n";
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
    q.printdequeue();
    q.display();
    q.dequeue();
    return 0;
}