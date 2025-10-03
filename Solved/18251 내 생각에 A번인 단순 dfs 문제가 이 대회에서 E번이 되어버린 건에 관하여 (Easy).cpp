//* https://www.acmicpc.net/problem/18251
//* Platinum 4

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N;
vector<ll> W;
vector<pair<int, ll>> seq;
int maxDepth = 0;

void dfs(int i, int depth)
{
    if (i > N)
        return;
    dfs(i * 2, depth + 1);
    seq.emplace_back(depth, W[i]);
    maxDepth = max(maxDepth, depth);
    dfs(i * 2 + 1, depth + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N))
        return 0;
    W.assign(N + 1, 0);
    for (int i = 1; i <= N; ++i)
        cin >> W[i];

    //* inorder seq with depths
    dfs(1, 0);
    int D = maxDepth + 1;

    ll answer = W[1];
    for (int i = 2; i <= N; ++i)
        answer = max(answer, W[i]);

    //* enumerate depth interval [a, b]
    for (int a = 0; a < D; ++a)
    {
        for (int b = a; b < D; ++b)
        {
            ll best = LLONG_MIN;
            ll curSum = 0;
            bool curHas = false; //* the current window contains at least one active node?

            for (auto [d, val] : seq)
            {
                bool active = (a <= d && d <= b);

                if (active)
                {
                    if (curHas)
                        curSum += val; //* extend
                    else
                    {
                        curSum = val;
                        curHas = true;
                    } //* start
                }
                else
                {
                    //* inactive nodes contribute 0 and can be inside the window,
                    //* but they cannot stat a window.
                    if (curHas)
                    {
                        curSum += 0; //* no-op
                    }
                    else
                    {
                        //* still cannot start
                    }
                }

                if (curHas)
                {
                    best = max(best, curSum);
                    if (curSum < 0)
                    {
                        curHas = false;
                        curSum = 0;
                    }
                }
            }
            if (best != LLONG_MIN)
                answer = max(answer, best);
        }
    }

    cout << answer;
    return 0;
}