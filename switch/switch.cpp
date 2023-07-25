#include <iostream>
using namespace std;

int main()
{
    char button;
    cout<<"Type a character: ";
    cin>>button;

    if(button == 'a')
    {
        cout<<"Hello!\n";
    }
    else if(button == 'b')
    {
        cout<<"Namaste!\n";
    }
    else if(button == 'c')
    {
        cout<<"Hola!\n";
    }
    else if(button == 'd')
    {
        cout<<"Salut!\n";
    }
    else if(button == 'e')
    {
        cout<<"Konnichiwa!\n";
    }
    else
    {
        cout<<"I don't know that language!\n";
    }

    return 0;
}