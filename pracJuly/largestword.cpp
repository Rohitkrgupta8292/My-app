#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;
    cin.ignore();

    char arr[n+1];
    cout<<"Enter the sentence: ";

    cin.getline(arr, n);
    cin.ignore();

    int i=0;
    int currlen=0, maxlen=0;
    int st=0, mxst = 0;


    while(1)
    {
        if(arr[i] == ' ' || arr[i] == '\0')
        {
            if(currlen > maxlen)
            {
                maxlen = currlen;
                mxst = st;
            }
            currlen = 0;
            st = i+1;
        }
        else
        currlen++;
        if(arr[i] == '\0')
            break;

        i++;   
    }
    cout<<"The length of Longest word in sentence is: ";
    cout<<maxlen<<endl;
    cout<<"The largest word is: ";
    for(int i=0; i<maxlen; i++)
    {
        cout<<arr[i+mxst];
    }
    cout<<endl;

    return 0;
}