//* https://www.acmicpc.net/problem/1167
//* Gold 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    if (!(cin >> V))
        return 0;
    vector<vector<pair<int, int>>> adj(V + 1);

    //* 입력: u v w v w ... -1
    for (int i = 0; i < V; ++i)
    {
        int u;
        cin >> u;
        while (true)
        {
            int v;
            cin >> v;
            if (v == -1)
                break;
            int w;
            cin >> w;
            adj[u].push_back({v, w});
        }
    }

    auto bfs = [&](int s) {
        vector<long long> dist(V + 1, -1);
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        int far = s;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto [v, w] : adj[u])
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + w;
                    q.push(v);
                    if (dist[v] > dist[far])
                        far = v;
                }
        }
        return pair<int, long long>(far, dist[far]);
    };

    //* 1) 임의 정점(1)에서 가장 먼 정점 A
    auto [A, _] = bfs(1);
    //* 2) A에서 가장 먼 거리 = 지름
    auto [B, diameter] = bfs(A);

    cout << diameter << '\n';
    return 0;
}
