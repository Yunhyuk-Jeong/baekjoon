//* https://www.acmicpc.net/problem/11659
//* Silver 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> psum(N + 1, 0LL);
    for (int i = 1; i <= N; ++i)
    {
        long long x;
        cin >> x;
        psum[i] = psum[i - 1] + x;
    }

    //* 각 질의 처리
    for (int q = 0; q < M; ++q)
    {
        int i, j;
        cin >> i >> j;
        long long ans = psum[j] - psum[i - 1];
        cout << ans << '\n';
    }

    return 0;
}
