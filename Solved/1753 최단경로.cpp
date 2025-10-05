//* https://www.acmicpc.net/problem/1753
//* Gold 4

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int INF = 0x3f3f3f3f; //* 충분히 큰 값

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, K;
    if (!(cin >> V >> E >> K))
        return 0;

    vector<vector<pii>> adj(V + 1);
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(V + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq; //* (dist, node)

    dist[K] = 0;
    pq.push({0, K});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue; //* 오래된 정보 무시(최적화)

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    ostringstream out;
    for (int i = 1; i <= V; ++i)
    {
        if (dist[i] == INF)
            out << "INF\n";
        else
            out << dist[i] << '\n';
    }
    cout << out.str();
    return 0;
}
