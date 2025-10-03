//* https://www.acmicpc.net/problem/9095
//* Silver 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;

    //* 문제 범위: n ≤ 11
    const int MAXN = 11;
    long long dp[MAXN + 1] = {0};
    dp[1] = 1; //* 1 = 1
    dp[2] = 2; //* 2 = 1+1, 2
    dp[3] = 4; //* 3 = 1+1+1, 1+2, 2+1, 3
    for (int i = 4; i <= MAXN; ++i)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    ostringstream out;
    while (T--)
    {
        int n;
        cin >> n;
        out << dp[n] << '\n';
    }
    cout << out.str();
    return 0;
}
