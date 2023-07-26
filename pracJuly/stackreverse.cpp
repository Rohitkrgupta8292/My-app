// reversing the stack using recursion method..//
#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(top);
}

void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int element = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, element);
}

void display(stack<int> &st)
{
    if (st.empty())
    {
        cout << "No element in the stack to print!\n";
        return;
    }
    for (int i = st.top(); i != 0; i--)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    display(st);
    reverse(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}