//* https://www.acmicpc.net/problem/2606
//* Silver 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; //* 컴퓨터 수
    int M; //* 간선 수
    if (!(cin >> N))
        return 0;
    cin >> M;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(N + 1, 0);
    int cnt = 0;

    //* DFS
    stack<int> st;
    st.push(1);
    vis[1] = 1;

    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        for (int v : adj[u])
            if (!vis[v])
            {
                vis[v] = 1;
                cnt++; //* 1에서 새로 도달한 컴퓨터 (1 제외)
                st.push(v);
            }
    }

    cout << cnt << '\n';
    return 0;
}
