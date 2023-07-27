// queue implementation using array..//
#include <bits/stdc++.h>
using namespace std;

#define n 100

class Queue
{
    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int x)
    {
        if (back == n - 1)
        {
            cout << "Queue overflow!\n";
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }

    void dequeue()
    {
        if (empty())
        {
            cout << "No element in queue to dequeue!\n";
            return;
        }
        front++;
    }

    int peek()
    {
        if (empty())
        {
            cout << "No element in queue to show!\n";
            return -1;
        }
        cout << "Front: ";
        return arr[front];
    }

    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }

    void display()
    {
        if (empty())
        {
            cout << "No element in queue to print!\n";
            return;
        }
        for (int i = front; i <= back; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void isEmpty()
    {
        if (empty())
        {
            cout << "No element in queue!\n";
        }
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
    q.enqueue(6);
    q.dequeue();
    q.dequeue();
    q.display();
    // cout << q.peek() << endl;
    q.dequeue();
    q.display();
    // cout << q.peek() << endl;
    q.dequeue();
    q.display();
    // cout << q.peek() << endl;
    q.dequeue();
    q.enqueue(7);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    cout << q.peek() << endl;
    q.isEmpty();
    return 0;
}