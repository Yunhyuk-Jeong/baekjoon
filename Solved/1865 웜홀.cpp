//* https://www.acmicpc.net/problem/1865
//* Gold 3

#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v;
    int w;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int N, M, W;
        cin >> N >> M >> W;

        vector<Edge> edges;
        edges.reserve(2 * M + W);

        //* 도로: 양방향 (+c)
        for (int i = 0; i < M; ++i)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        //* 웜홀: 단방향 (-c)
        for (int i = 0; i < W; ++i)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        const int INF = 0x3f3f3f3f;
        vector<int> dist(N + 1, 0);
        //* 모든 정점 dist=0 로 시작 → 슈퍼소스와 같은 효과

        bool updated = false;
        //* N-1번 완화
        for (int i = 1; i <= N - 1; ++i)
        {
            updated = false;
            for (const auto &ed : edges)
            {
                if (dist[ed.v] > dist[ed.u] + ed.w)
                {
                    dist[ed.v] = dist[ed.u] + ed.w;
                    updated = true;
                }
            }
            if (!updated)
                break; //* 더 이상 개선 없으면 조기 종료
        }

        //* 한 번 더 완화가 되면 음수 사이클 존재
        bool hasNegCycle = false;
        if (updated)
        {
            for (const auto &ed : edges)
            {
                if (dist[ed.v] > dist[ed.u] + ed.w)
                {
                    hasNegCycle = true;
                    break;
                }
            }
        }

        cout << (hasNegCycle ? "YES" : "NO") << '\n';
    }
    return 0;
}
