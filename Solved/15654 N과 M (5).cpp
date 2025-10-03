//* https://www.acmicpc.net/problem/15654
//* Silver 3

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
        {
            out << pick[i] << (i + 1 == M ? '\n' : ' ');
        }
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        if (used[i])
            continue;
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