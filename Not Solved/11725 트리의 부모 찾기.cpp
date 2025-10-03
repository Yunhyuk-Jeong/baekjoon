//* https://www.acmicpc.net/problem/11725
//* Silver 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(N + 1, 0);
    vector<char> vis(N + 1, 0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (!vis[v])
            {
                vis[v] = 1;
                parent[v] = u;
                q.push(v);
            }
    }

    ostringstream out;
    for (int i = 2; i <= N; ++i)
        out << parent[i] << '\n';
    cout << out.str();
    return 0;
}