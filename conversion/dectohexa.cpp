// decimal to Hexadecimal.
#include <bits/stdc++.h>
using namespace std;

string decimalToHexa(int n)
{ 
   int x = 1;
   string ans = "";
   while (x <= n)
   {
      x*=16;
   }
   x/=16;
   while (x > 0)
   {
       int r = n/x;
       n -= r*x;
       x /= 16;
       if (r <= 9)
       {
          ans = ans + to_string(r);
       }
       else
       {
          char c = 'A' + r - 10;
          ans.push_back(c);
       }
   }
   return ans;

}

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;

    cout<<decimalToHexa(n)<<endl;
    return 0;
}