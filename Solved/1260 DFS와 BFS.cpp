//* https://www.acmicpc.net/problem/1260
//* Silver 2

#include <bits/stdc++.h>
using namespace std;

int N, M, V;
vector<vector<int>> adj;
vector<int> visited;

void dfs(int u, ostringstream &out)
{
    visited[u] = 1;
    out << u << ' ';
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v, out);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> V;
    adj.assign(N + 1, {});
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end()); //* 작은 번호 우선
    }

    ostringstream out;

    //* DFS
    visited.assign(N + 1, 0);
    dfs(V, out);
    out << '\n';

    //* BFS
    visited.assign(N + 1, 0);
    queue<int> q;
    q.push(V);
    visited[V] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        out << u << ' ';
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    out << '\n';

    cout << out.str();
    return 0;
}
