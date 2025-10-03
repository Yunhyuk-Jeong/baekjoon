//* https://www.acmicpc.net/problem/11724
//* Silver 2

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

    vector<char> vis(N + 1, 0);
    int components = 0;

    for (int s = 1; s <= N; ++s)
    {
        if (vis[s])
            continue;
        components++;
        //* iterative DFS
        stack<int> st;
        st.push(s);
        vis[s] = 1;
        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            for (int v : adj[u])
                if (!vis[v])
                {
                    vis[v] = 1;
                    st.push(v);
                }
        }
    }

    cout << components << '\n';
    return 0;
}
