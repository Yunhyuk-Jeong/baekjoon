//* https://www.acmicpc.net/problem/17353
//* Platinum 2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BIT
{
    int n;
    vector<ll> t;
    BIT(int n = 0) : n(n), t(n + 1, 0)
    {
    }
    void add(int i, ll v)
    {
        for (; i <= n; i += i & -i)
            t[i] += v;
    }
    ll sum(int i) const
    {
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s += t[i];
        return s;
    }
    void addRange(int l, int r, ll v)
    {
        if (l > r)
            return;
        add(l, v);
        if (r + 1 <= n)
            add(r + 1, -v);
    }

    ll point(int i) const
    {
        return sum(i);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;

    vector<ll> A(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    int Q;
    cin >> Q;

    vector<ll> ans(Q);
    int ansIdx = 0;

    BIT bitA(N), bitB(N);

    while (Q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int L, R;
            cin >> L >> R;
            bitA.addRange(L, R, 1);
            bitB.addRange(L, R, -(ll)(L - 1));
        }
        else if (type == 2)
        {
            int X;
            cin >> X;
            ll a = bitA.point(X);
            ll b = bitB.point(X);
            ll res = A[X] + a * (ll)X + b;
            ans[ansIdx] = res;
            ansIdx++;
        }
    }

    for (int i = 0; i < ansIdx; i++)
        cout << ans[i] << '\n';

    return 0;
}