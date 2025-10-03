//* https://www.acmicpc.net/problem/1003
//* Silver 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    const int MAXN = 40;
    long long dp[MAXN + 1][2] = {0};
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= MAXN; ++i)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }

    string output;
    output.reserve(T * 20);

    while (T--)
    {
        int n;
        cin >> n;
        output += to_string(dp[n][0]) + ' ' + to_string(dp[n][1]) + '\n';
    }

    cout << output;
    return 0;
}
