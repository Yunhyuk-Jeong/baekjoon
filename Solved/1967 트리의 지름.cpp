//* https://www.acmicpc.net/problem/1967
//* Gold 4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;

    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    auto farthest_from = [&](int start) {
        vector<long long> dist(N + 1, -1);
        dist[start] = 0;
        //* 반복 DFS (스택) — (노드, 부모)
        stack<pair<int, int>> st;
        st.push({start, 0});
        while (!st.empty())
        {
            auto [u, p] = st.top();
            st.pop();
            for (auto [v, w] : adj[u])
                if (v != p)
                {
                    dist[v] = dist[u] + w;
                    st.push({v, u});
                }
        }
        int idx = start;
        for (int i = 1; i <= N; ++i)
            if (dist[i] > dist[idx])
                idx = i;
        return pair<int, long long>(idx, dist[idx]);
    };

    //* 1) 임의 정점(1)에서 가장 먼 정점 A
    auto [A, _d] = farthest_from(1);
    //* 2) A에서 가장 먼 거리 = 지름
    auto [B, diameter] = farthest_from(A);

    cout << diameter << '\n';
    return 0;
}
