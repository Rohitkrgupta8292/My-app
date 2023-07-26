#include <bits/stdc++.h>
using namespace std;

#define n 100

class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "stack is full!\n";
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop!\n";
            return;
        }

        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "No element in the stack!\n";
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "No element in the stack to print!\n";
            return;
        }
        for (int i = top; i != -1; i--)
        {
            cout << arr[i] << " ";
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
    st.display();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.display();
    cout << st.empty() << endl;
    return 0;
}