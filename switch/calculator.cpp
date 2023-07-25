#include <iostream>
using namespace std;

int main()
{
    float n1,n2,answer;
    
    cout<<"\t*****************\n";
    cout<<"\tOperators\n";
    cout<<"\t*****************\n";
    cout<<"\tArithmatic Operation\n";
    cout<<"\t(A)Additon\n";
    cout<<"\t(B)Subtraction\n";
    cout<<"\t(C)Multiplication\n";
    cout<<"\t(D)Division\n";
    cout<<"\t(E)Exit\n";
    cout<<"\t*****************\n";

    char op;
    cout<<"Enter an operator: ";
    cin>>op;
    
if(op>=65 && op<69) 
{
    cout<<"Enter the first number: ";
    cin>>n1;
    cout<<"Enter the second number: ";
    cin>>n2;
}

    switch(op)
    {
        case 'A':
              answer=n1+n2;
              cout<<"The Addition is: "<<answer<<endl;
              break;

        case 'B':
              answer=n1-n2;
              cout<<"The Substraction is: "<<answer<<endl;
              break;

        case 'C':
              answer=n1*n2;
              cout<<"The Multiplication is: "<<answer<<endl;
              break;
        case 'D':
              answer=n1/n2;
              cout<<"The Division is: "<<answer<<endl;
              break;

        case 'E':
                 cout<<"Exiting the program\n";
                 exit(0);
                 break;

        default:
               cout<<"Invalid choice"<<endl;
               break;
    }

    return 0;
}
    