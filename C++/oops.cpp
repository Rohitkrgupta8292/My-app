#include <bits/stdc++.h>
using namespace std;

class student
{
    string name;
public:
    int age;
    bool gender;

    void setName(string s){
        name = s;
    }

    void printInfo()
    {
        cout << "Name: ";
        cout << name << endl;
        cout << "Age: ";
        cout << age << endl;
        cout << "Gender: ";
        cout << gender << endl;
    }
};

int main()
{

    // student a;
    // a.name ='Urvi';
    // a.age= '20';
    // a.gender=1;

    student arr[3];
    for (int i = 0; i < 3; i++)
    {
        string s;
        cout << "Name: ";
        cin >> s;
        arr[i].setName(s);
        cout << "Age: ";
        cin >> arr[i].age;
        cout << "Gender: ";
        cin >> arr[i].gender;
    }
    cout << "The Information of Students:\n";
    for (int i = 0; i < 3; i++)
    {
        arr[i].printInfo();
    }

    return 0;
}