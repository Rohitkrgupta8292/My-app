// stack implementation using array..//
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;

public:
    Stack()
    {
        arr = new int[size];
        size = 80;
        top = -1; // -1 for empty stack.
    }

    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
        cout << "Pushed Element: " << val << endl;
    }

    void pop()
    {
        if (Empty())
        {
            cout << "stack is Empty" << endl;
            return;
        }
        int popped = arr[top--];
        cout << "Poped element:" << popped << endl;
    }
    bool Empty()
    {
        return top == -1;
    }

    int peek()
    {
        if (Empty())
        {
            cout << "No element in the stack\n";
            return -1;
        }
        return arr[top];
    }

    void display()
    {
        if (Empty())
        {
            cout << "No element to print" << endl;
            return;
        }
        int i = top;
        cout<<"Stack Elements: ";
        while (i != -1)
        {
            cout << arr[i] << " ";
            i--;
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
    cout<<"Top Element: "<<st.peek()<<endl;
    st.pop();
    st.pop();
    cout<<"Top Element: "<<st.peek()<<endl;
    st.display();
    st.pop();
    st.pop();
    st.display();
    st.pop();
    cout<<"Top Element: "<<st.peek()<<endl;
    return 0;
}