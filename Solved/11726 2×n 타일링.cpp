//* https://www.acmicpc.net/problem/11726
//* Silver 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    const int MOD = 10007;
    vector<int> dp(max(3, n + 1), 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    cout << dp[n] << '\n';
    return 0;
}
