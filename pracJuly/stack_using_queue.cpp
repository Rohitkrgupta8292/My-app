#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int size;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        size = 0;
    }

    void push(int val)
    {
        q2.push(val);
        size++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop()
    {
        if (q1.empty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        int Pop = q1.front();
        q1.pop();
        size--;
        return Pop;
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return q1.front();
    }

    int Size()
    {
        return size;
    }

    void display()
    {
        if (q1.empty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "All element in Queue: ";
        for (int i = q1.front(); i != q1.empty(); i--)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    cout << "Popped element: " << st.pop() << endl;
    cout << "Top element:" << st.top() << endl;
    st.display();
    cout << "Size:" << st.Size() << endl;
    cout << "Popped element: " << st.pop() << endl;
    cout << "Top element:" << st.top() << endl;
    st.display();
    cout << "Popped element: " << st.pop() << endl;
    cout << "Top element:" << st.top() << endl;
    st.display();
    cout << "Popped element: " << st.pop() << endl;
    cout << "Top element:" << st.top() << endl;
    st.display();
    cout << "Popped element: " << st.pop() << endl;
    cout << "Top element:" << st.top() << endl;
    st.display();
    return 0;
}