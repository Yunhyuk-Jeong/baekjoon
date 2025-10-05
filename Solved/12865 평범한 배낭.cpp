//* https://www.acmicpc.net/problem/12865
//* Gold 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;
    vector<pair<int, int>> item(N);
    for (int i = 0; i < N; ++i)
        cin >> item[i].first >> item[i].second; //* (w, v)

    vector<int> dp(W + 1, 0);
    for (auto [w, v] : item)
    {
        for (int x = W; x >= w; --x)
        {
            dp[x] = max(dp[x], dp[x - w] + v);
        }
    }
    cout << dp[W] << '\n';
    return 0;
}
