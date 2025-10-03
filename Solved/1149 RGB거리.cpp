//* https://www.acmicpc.net/problem/1149
//* Silver 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<array<int, 3>> cost(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    const int INF = 1e9;
    vector<array<int, 3>> dp(N + 1, {INF, INF, INF});

    //* 첫 집 기본값
    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];

    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    int ans = min({dp[N][0], dp[N][1], dp[N][2]});
    cout << ans << "\n";
    return 0;
}
