//* https://www.acmicpc.net/problem/13549
//* Gold 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K))
        return 0;

    if (N >= K)
    { //* 뒤로만 가면 되는 특수 케이스
        cout << (N - K) << '\n';
        return 0;
    }

    const int MAX = 200000; //* 탐색 상한
    const int INF = 1e9;
    vector<int> dist(MAX + 1, INF);
    deque<int> dq;

    dist[N] = 0;
    dq.push_front(N);

    while (!dq.empty())
    {
        int x = dq.front();
        dq.pop_front();
        if (x == K)
        { //* 최단 시간 도달
            cout << dist[x] << '\n';
            return 0;
        }

        //* 0초 이동: x -> 2x
        long long nx = 1LL * x * 2;
        if (nx <= MAX && dist[nx] > dist[x])
        {
            dist[nx] = dist[x];
            dq.push_front((int)nx);
        }

        //* 1초 이동: x -> x-1
        if (x - 1 >= 0 && dist[x - 1] > dist[x] + 1)
        {
            dist[x - 1] = dist[x] + 1;
            dq.push_back(x - 1);
        }

        //* 1초 이동: x -> x+1
        if (x + 1 <= MAX && dist[x + 1] > dist[x] + 1)
        {
            dist[x + 1] = dist[x] + 1;
            dq.push_back(x + 1);
        }
    }

    //* 이론상 여기 오지 않음
    cout << dist[K] << '\n';
    return 0;
}
