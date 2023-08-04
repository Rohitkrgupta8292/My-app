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

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    bool Empty()
    {
        // if (top == NULL)
        // {
        //     return true;
        // }
        return top == NULL;
    }

    void push(int val)
    {
        Node *n = new Node(val);
        n->next = top;
        top = n;
        cout << "Pushed Element: " << top->data << endl;
    }

    void pop()
    {
        if (Empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *todelete = top;
        int x = todelete->data;
        top = top->next;
        delete todelete;
        cout << "Popped element : " << x << endl;
    }

    int peek()
    {
        if (Empty())
        {
            cout << "No element in top" << endl;
            return -1;
        }
        return top->data;
    }

    void display()
    {
        if (Empty())
        {
            cout << "No element in stack to print";
        }

        Node *ptr = top;
        cout << "Stack Element: ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
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
    st.display();
    cout << "Top Element: " << st.peek()<<endl;
    st.pop();
    st.pop();
    st.push(4);
    st.display();
    cout << "Top Element: " << st.peek()<<endl;
    st.pop();
    st.pop();
    st.display();
    cout << "Top Element: " << st.peek()<<endl;
    st.pop();
    return 0;
}