//* https://www.acmicpc.net/problem/15650
//* Silver 3

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> comb;

void dfs(int start)
{
    if ((int)comb.size() == M)
    {
        for (int x : comb)
            cout << x << ' ';
        cout << '\n';
        return;
    }
    for (int num = start; num <= N; num++)
    {
        comb.push_back(num);
        dfs(num + 1);
        comb.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    dfs(1);
    return 0;
}
