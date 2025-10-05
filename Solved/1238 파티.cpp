//* https://www.acmicpc.net/problem/1238
//* Gold 3

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int INF = 1e9;

vector<int> dijkstra(int N, int src, const vector<vector<pii>> &G)
{
    vector<int> dist(N + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto [cd, u] = pq.top();
        pq.pop();
        if (cd != dist[u])
            continue;
        for (auto [v, w] : G[u])
        {
            if (dist[v] > cd + w)
            {
                dist[v] = cd + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X;
    if (!(cin >> N >> M >> X))
        return 0;

    vector<vector<pii>> G(N + 1), GR(N + 1); //* GR: 간선 뒤집은 그래프
    for (int i = 0; i < M; ++i)
    {
        int a, b, t;
        cin >> a >> b >> t;
        G[a].push_back({b, t});
        GR[b].push_back({a, t});
    }

    //* X -> i
    auto distFromX = dijkstra(N, X, G);
    //* i -> X  ==  (뒤집은 그래프에서) X -> i
    auto distToX = dijkstra(N, X, GR);

    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (distFromX[i] == INF || distToX[i] == INF)
            continue; //* 도달 불가면 스킵(문제상 거의 없음)
        ans = max(ans, distFromX[i] + distToX[i]);
    }
    cout << ans << '\n';
    return 0;
}
