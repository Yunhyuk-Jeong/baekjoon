//* https://www.acmicpc.net/problem/20492
//* Bronze 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N))
        return 0;

    cout << (N * 78 / 100) << ' ' << (N * 956 / 1000) << '\n';
    return 0;
}
