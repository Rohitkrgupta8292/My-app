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

    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        size--;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void push(int x)
    {
        q1.push(x);
        size++;
    }

    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }

    int Size()
    {
        return size;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<< "Top Element: " <<st.top()<<endl;
    st.pop();
    cout<< "Top Element: " <<st.top()<<endl;
    cout<<"size: "<<st.Size()<<endl;;
    return 0;
}