//* https://www.acmicpc.net/problem/11375
//* Platinum 4

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> matchR;
vector<char> visited;

bool dfs(int u)
{
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        visited[v] = 1;
        if (matchR[v] == -1 || dfs(matchR[v]))
        {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.assign(N + 1, {});
    for (int i = 1; i <= N; ++i)
    {
        int cnt;
        cin >> cnt;
        while (cnt--)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    matchR.assign(M + 1, -1);

    int result = 0;
    for (int i = 1; i <= N; ++i)
    {
        visited.assign(M + 1, 0);
        if (dfs(i))
            result++;
    }

    cout << result << "\n";
    return 0;
}
