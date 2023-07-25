// print hello in different languages using swtich statement.
#include <iostream>
using namespace std;

int main()
{
    char button;
    cout<<"Type a character: ";
    cin>>button;
    
    switch (button)
    {
    case 'a':
        cout<<"Hello!\n";
        break;

    case 'b':
        cout<<"Namaste!\n";
        break;

    case 'c':
        cout<<"Hola!\n";
        break;

    case 'd':
        cout<<"Salut!\n";
        break;   

     case 'e':
        cout<<"Kochinawa!\n";
        break;        
    
    default:
    cout<<"I am still learning more!\n";
        break;
    }
    
    return 0;
}     