//* https://www.acmicpc.net/problem/9465
//* Silver 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> top(N + 1), bottom(N + 1);
        for (int i = 1; i <= N; ++i)
            cin >> top[i];
        for (int i = 1; i <= N; ++i)
            cin >> bottom[i];

        long long up = 0, down = 0, none = 0; //* i-1 열까지의 값
        //* i = 1
        long long nup = top[1];
        long long ndown = bottom[1];
        long long nnone = 0;
        up = nup;
        down = ndown;
        none = nnone;

        for (int i = 2; i <= N; ++i)
        {
            long long nu = max(down, none) + top[i];
            long long nd = max(up, none) + bottom[i];
            long long nn = max({up, down, none});
            up = nu;
            down = nd;
            none = nn;
        }

        cout << max({up, down, none}) << '\n';
    }
    return 0;
}
