// Number theory advance = extended euclid algorithm gcd(a,b)..//
#include <bits/stdc++.h>
using namespace std;
// ax + by = gcd(a,b)..//
// gcd(d,0) = d..//
// ax + 0 =  a->x=1
struct triplet
{
    int x, y, gcd;
};

triplet extendedEuclid(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }
    triplet smallans = extendedEuclid(b, a % b);
    triplet ans;
    ans.gcd = smallans.gcd;
    ans.x = smallans.y;
    ans.y = smallans.x - (a / b) * smallans.y;
    return ans;
}

int main()
{
    int a, b;
    cout << " A and B: ";
    cin >> a >> b;
    triplet ans = extendedEuclid(a,b);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y;
    return 0;
}