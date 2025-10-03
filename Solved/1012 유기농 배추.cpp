//* https://www.acmicpc.net/problem/1012
//* Silver 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;

    ostringstream out; //* 결과를 모아서 한 번에 출력

    while (T--)
    {
        int M, N, K; //* M: 가로(열) 길이, N: 세로(행) 길이, K: 배추 개수
        cin >> M >> N >> K;

        //* grid[y][x], y in [0..N-1], x in [0..M-1]
        vector<vector<char>> grid(N, vector<char>(M, 0));
        for (int i = 0; i < K; ++i)
        {
            int x, y;
            cin >> x >> y;
            grid[y][x] = 1; //* 배추 있음
        }

        int components = 0;
        //* 4방향
        const int dy[4] = {-1, 1, 0, 0};
        const int dx[4] = {0, 0, -1, 1};

        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                if (!grid[y][x])
                    continue; //* 배추가 없거나 이미 방문(0 처리)된 칸
                //* 시작 탐색: BFS
                ++components;
                queue<pair<int, int>> q;
                q.push({y, x});
                grid[y][x] = 0; //* 방문 처리

                while (!q.empty())
                {
                    auto [cy, cx] = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int ny = cy + dy[dir];
                        int nx = cx + dx[dir];
                        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                            continue;
                        if (!grid[ny][nx])
                            continue;
                        grid[ny][nx] = 0; //* 방문
                        q.push({ny, nx});
                    }
                }
            }
        }

        out << components << '\n';
    }

    cout << out.str();
    return 0;
}
