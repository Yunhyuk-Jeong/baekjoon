//* https://www.acmicpc.net/problem/2630
//* Silver 2

#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> A;
int whiteCnt = 0, blueCnt = 0;

void solve(int y, int x, int len)
{
    int first = A[y][x];
    bool same = true;
    for (int i = y; i < y + len && same; ++i)
        for (int j = x; j < x + len; ++j)
            if (A[i][j] != first)
            {
                same = false;
                break;
            }

    if (same)
    {
        if (first == 0)
            ++whiteCnt;
        else
            ++blueCnt;
        return;
    }
    int h = len / 2;
    solve(y, x, h);
    solve(y, x + h, h);
    solve(y + h, x, h);
    solve(y + h, x + h, h);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.assign(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];

    solve(0, 0, N);
    cout << whiteCnt << '\n' << blueCnt << '\n';
    return 0;
}
