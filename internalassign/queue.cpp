#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> myQueue;
    vector<int> elements = {15, 16, 17, 18, 19, 20};

    // Inserting elements into the queue.
    for (int element : elements)
    {
        myQueue.push(element);
    }

    cout <<"Queue: ";

    // Dequeuing and printing the sequence
    while (!myQueue.empty())
    {
        cout << myQueue.front() << ",";
        myQueue.pop();
    }
    cout<<endl;
    return 0;
}