//* https://www.acmicpc.net/problem/2420
//* Bronze 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    if (!(cin >> N >> M))
        return 0;
    cout << llabs(N - M) << '\n';
    return 0;
}
