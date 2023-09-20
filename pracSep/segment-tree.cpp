#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int a[N] = {5, 3, 2, 4, 1, 8, 6, 10}, tree[4 * N];

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r)
{
    if (l > end || r < start)
    {
        return 0;
    }
    if (l <= start && end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int q1 = query(2 * node, start, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, end, l, r);
    return q1 + q2;
}

int main()
{
    int n = 8;
    build(1, 0, n - 1);
    // for (int i = 1; i <=15; i++)
    // {
    //     cout << tree[i] << endl;
    // }

    while (1)
    {
        int type;
        cin >> type;
        if (type == -1)
        {
            break;
        }
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;

            int ans = query(1, 0, n - 1, l, r);
            cout << ans << endl;
        }
    }

    return 0;
}