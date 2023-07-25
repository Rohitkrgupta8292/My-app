// Hexadecimal to decimal.
#include <bits/stdc++.h>
using namespace std;

int hexaToDecimal(string n)
{
    int ans = 0;
    int x = 1;
    int s = n.size();
    for (int i = s - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            ans += (n[i] - '0') * x;
        }
        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            ans += (n[i] - 'A' + 10) * x;
        }
        x *= 16;
    }

    return ans;
}    


int main()
{
    string n;
    cout<<"N: ";
    cin>>n;

    cout<<hexaToDecimal(n)<<endl;
    return 0;
}