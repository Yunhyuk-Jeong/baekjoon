//* https://www.acmicpc.net/problem/1389
//* Silver 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M))
        return 0;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int bestNode = 1;
    int bestSum = INT_MAX;

    //* 각 사람 i에 대해 BFS로 최단거리 합 계산
    for (int i = 1; i <= N; ++i)
    {
        vector<int> dist(N + 1, -1);
        queue<int> q;
        dist[i] = 0;
        q.push(i);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        int sum = 0;
        for (int j = 1; j <= N; ++j)
            sum += dist[j];

        if (sum < bestSum)
        {
            bestSum = sum;
            bestNode = i;
        }
    }

    cout << bestNode << '\n';
    return 0;
}
