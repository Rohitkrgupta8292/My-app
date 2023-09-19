#include <bits/stdc++.h>
using namespace std;

int p = 31;
const int N = 1e5 + 7, m = 1e9 + 7;
vector<long long> powers(N);
int main()
{
    string s = "na";
    string t = "apnaacollegena";
    int T = t.size(), S = s.size();

    powers[0] = 1;
    for (int i = 1; i < N; i++)
    {
        powers[i] = (powers[i - 1] * p) % m;
    }

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * powers[i]) % m;
    }

    long long hash = 0;
    for (int i = 0; i < S; i++)
    {
        hash = (hash + (s[i] - 'a' + 1) * powers[i]) % m;
    }
    for (int i = 0; i + S - 1 < T; i++)
    {
        long long curr_hash = (h[i + S] - h[i] + m) % m;
        if (curr_hash == (hash * powers[i]) % m)
        {
            cout << "Found at index: " << i << endl;
        }
    }
}