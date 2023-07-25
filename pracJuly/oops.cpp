#include <bits/stdc++.h>
using namespace std;

class student
{
    string name;

public:
    int age;
    bool gender;

    student()
    {
        cout << "Default constructor!\n";
    } // default constructor..//

    student(string s, int a, int g)
    {
        cout << "Parameterised Constructor!\n";
        name = s;
        age = a;
        gender = g;
    } // Parameterised constructor..//

    student(student &a)
    {
        cout << "Copy Constructor!\n";
        name = a.name;
        age = a.age;
        gender = a.gender;
    } // copy constructor..//

    ~student()
    {
        cout << "Destructor!\n";
    }

    void setName(string s)
    {
        name = s;
    }

    void getName(string s)
    {
        cout << name;
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

    bool operator == (student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    // student a;
    // a.name ='Urvi';
    // a.age= '20';
    // a.gender=1;

    // student arr[3];
    // for (int i = 0; i < 3; i++)
    //   {
    //     string s;
    //        cout << "Name: ";
    //        cin >> s;
    //        arr[i].setName(s);
    //       cout << "Age: ";
    //       cin >> arr[i].age;
    //       cout << "Gender: ";
    //      cin >> arr[i].gender;
    //  }
    // cout << "The Information of Students:\n";
    // for (int i = 0; i < 3; i++)
    // {
    //     arr[i].printInfo();
    // }
    // string s;
    student a("Urvi", 20, 1); // calling parmeterised constructor..//
                              // a.printInfo();
    // a.getName(s);

    student b("Rahul", 21, 0);     // Default constructor..//
    student c = a; // Copy constructor..//

    if (b == a)
    {
        cout << "same\n";
    }
    else
    {
        cout << "Not Same\n";
    }
    
    return 0;
}