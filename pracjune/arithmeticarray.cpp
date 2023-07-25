#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        int array = 0;
        array = i + 1;
        cout<<"array "<<array<<":";
        cin >> a[i];
    }

    int ans = 2;
    int pd = a[1] - a[1-0];
    int j=2;
    int curr = 2;

    while(j<n)
    {
        if(pd == a[j]-a[j-1])
        {
            curr++;
        }
        else
        {
            pd = a[j] - a[j-1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }
    cout<<"Length:"<<ans<<endl;
    return 0;
}