//* https://www.acmicpc.net/problem/15663
//* Silver 2

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> a, pick;
vector<char> used;
ostringstream out;

void dfs(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; ++i)
            out << pick[i] << (i + 1 == M ? '\n' : ' ');
        return;
    }
    int prev = INT_MIN; //* 이 깊이에서 마지막으로 쓴 값(중복 수열 방지용)
    for (int i = 0; i < N; ++i)
    {
        if (used[i])
            continue;
        if (a[i] == prev)
            continue; //* 같은 깊이에서 같은 값은 한 번만
        prev = a[i];
        used[i] = 1;
        pick[depth] = a[i];
        dfs(depth + 1);
        used[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    a.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

    used.assign(N, 0);
    pick.assign(N, 0);

    dfs(0);
    cout << out.str();
    return 0;
}