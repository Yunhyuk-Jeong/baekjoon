//* https://www.acmicpc.net/problem/11404
//* Gold 4

#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<long long>> dist(N + 1, vector<long long>(N + 1, INF));

    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] == INF)
                cout << 0;
            else
                cout << dist[i][j];
            if (j < N)
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
