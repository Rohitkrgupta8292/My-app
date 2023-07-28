// queue implementation using stack..//
#include <bits/stdc++.h>
using namespace std;
/*
class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int x)
    {
        s1.push(x);
        return;
    }

    int dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }

    bool empty()
    {
        if (s1.empty() and s2.empty())
        {
            return true;
        }
        return false;
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
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(6);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(7);
    cout<<q.dequeue()<<endl;
    cout<<q.empty()<<endl;

    return 0;
}
*/

// queue implementation using stack..//
#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1;

public:
    void enqueue(int x)
    {
        s1.push(x);
        return;
    }

    int dequeue()
    {
        if (s1.empty())
        {
            cout << "Queue is empty!\n";
            exit(0);
        }
        int x = s1.top();
        s1.pop();
        if (s1.empty())
        {
            return x;
        }
        int item = dequeue();
        s1.push(x);
        return item;
    }

    bool empty()
    {
        if (s1.empty())
        {
            return true;
        }
        return false;
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
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(6);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(7);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.empty() << endl;
}