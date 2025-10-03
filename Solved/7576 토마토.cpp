//* https://www.acmicpc.net/problem/7576
//* Gold 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N; //* M: 가로(열), N: 세로(행)
    if (!(cin >> M >> N))
        return 0;

    vector<vector<int>> a(N, vector<int>(M));
    queue<pair<int, int>> q;
    int unripe = 0;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            cin >> a[y][x];
            if (a[y][x] == 1)
                q.push({y, x}); //* 익은 토마토 시작점
            else if (a[y][x] == 0)
                unripe++; //* 안 익은 개수 카운트
        }
    }

    if (unripe == 0)
    {
        cout << 0 << '\n';
        return 0;
    } //* 이미 모두 익음

    const int dy[4] = {-1, 1, 0, 0};
    const int dx[4] = {0, 0, -1, 1};
    int days = -1;

    //* 레벨 BFS: 하루 단위로 확장
    while (!q.empty())
    {
        int qs = q.size();
        days++; //* 새 하루 시작
        while (qs--)
        {
            auto [y, x] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d)
            {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                    continue;
                if (a[ny][nx] != 0)
                    continue;  //* 이미 익었거나 빈 칸(-1)
                a[ny][nx] = 1; //* 오늘 익음
                unripe--;
                q.push({ny, nx});
            }
        }
    }

    if (unripe > 0)
        cout << -1 << '\n';
    else
        cout << days << '\n';
    return 0;
}
