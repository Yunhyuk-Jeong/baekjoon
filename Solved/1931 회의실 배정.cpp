//* https://www.acmicpc.net/problem/1931
//* Gold 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;

    vector<pair<int, int>> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), [](const auto &x, const auto &y) {
        if (x.second != y.second)
            return x.second < y.second;
        return x.first < y.first;
    });

    int cnt = 0;
    int lastEnd = 0;
    for (auto &[s, e] : a)
    {
        if (s >= lastEnd)
        {
            cnt++;
            lastEnd = e;
        }
    }

    cout << cnt << '\n';
    return 0;
}
