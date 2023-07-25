#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    stack <int> myStack;
    vector <int> elements = {10,20,30,40,50};

    // Push elements into the stack.
    for (int element : elements)
    {
        myStack.push(element);
    } 
    // display stack.
    cout << "Stack: ";

    // Pop elements from the stack and print the sequence
    while (!myStack.empty())
    {
        cout << myStack.top() << ",";
        myStack.pop();
    }
    cout << endl;
    return 0;
}