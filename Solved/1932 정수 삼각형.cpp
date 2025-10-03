//* https://www.acmicpc.net/problem/1932
//* Silver 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> dp(N + 1, 0); //* dp[j]: 현재 줄까지 j번째 칸의 최대합
    for (int i = 1; i <= N; ++i)
    {
        //* 입력을 한 줄 읽고, 오른쪽 -> 왼쪽으로 갱신
        for (int j = i; j >= 1; --j)
        {
            int x;
            cin >> x;
            if (j == 1)
                dp[j] = dp[j] + x; //* 맨 왼쪽
            else if (j == i)
                dp[j] = dp[j - 1] + x; //* 맨 오른쪽
            else
                dp[j] = max(dp[j - 1], dp[j]) + x; //* 가운데
        }
    }

    cout << *max_element(dp.begin() + 1, dp.begin() + N + 1);
    return 0;
}