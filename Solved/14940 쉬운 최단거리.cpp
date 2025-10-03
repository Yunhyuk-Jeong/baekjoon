//* https://www.acmicpc.net/problem/14940
//* Silver 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> mp(N, vector<int>(M));
    int sy = -1, sx = -1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 2)
            {
                sy = i;
                sx = j;
            }
        }
    }

    const int dy[4] = {-1, 1, 0, 0};
    const int dx[4] = {0, 0, -1, 1};

    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> q;
    dist[sy][sx] = 0;
    q.push({sy, sx});

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d)
        {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (mp[ny][nx] == 0)
                continue; //* 벽은 못 감
            if (dist[ny][nx] != -1)
                continue; //* 이미 방문
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    //* 출력
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (mp[i][j] == 0)
            {
                cout << 0;
            }
            else
            {
                cout << dist[i][j];
            }
            if (j < M - 1)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
