//* https://www.acmicpc.net/problem/2206
//* Gold 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; ++i)
        cin >> grid[i];

    //* dist[y][x][b] : (y,x)에 b상태(0:안부숨,1:부숨)로 도달한 최단거리
    vector<vector<array<int, 2>>> dist(N, vector<array<int, 2>>(M, {0, 0}));
    queue<tuple<int, int, int>> q;

    dist[0][0][0] = 1;
    q.push({0, 0, 0});

    const int dy[4] = {-1, 1, 0, 0};
    const int dx[4] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto [y, x, b] = q.front();
        q.pop();
        if (y == N - 1 && x == M - 1)
        {
            cout << dist[y][x][b] << '\n';
            return 0;
        }
        for (int d = 0; d < 4; ++d)
        {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;

            if (grid[ny][nx] == '0')
            {
                if (!dist[ny][nx][b])
                {
                    dist[ny][nx][b] = dist[y][x][b] + 1;
                    q.push({ny, nx, b});
                }
            }
            else
            { //* '1' 벽
                if (b == 0 && !dist[ny][nx][1])
                {
                    dist[ny][nx][1] = dist[y][x][0] + 1;
                    q.push({ny, nx, 1});
                }
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
