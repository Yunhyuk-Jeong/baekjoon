//* https://www.acmicpc.net/problem/1676
//* Silver 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;

    int cnt = 0;
    for (long long p = 5; p <= N; p *= 5)
        cnt += N / p;

    cout << cnt << '\n';

    return 0;
}