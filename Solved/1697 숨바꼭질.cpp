//* https://www.acmicpc.net/problem/1697
//* Silver 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    const int MAX = 100000;
    vector<int> dist(MAX + 1, -1);
    queue<int> q;

    dist[N] = 0;
    q.push(N);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == K)
        {
            cout << dist[x] << "\n";
            return 0;
        }
        int moves[3] = {x - 1, x + 1, x * 2};
        for (int m : moves)
        {
            if (m < 0 || m > MAX)
                continue;
            if (dist[m] != -1)
                continue;
            dist[m] = dist[x] + 1;
            q.push(m);
        }
    }

    return 0;
}
