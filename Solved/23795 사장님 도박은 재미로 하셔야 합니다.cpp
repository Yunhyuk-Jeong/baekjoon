//* https://www.acmicpc.net/problem/23795
//* Bronze 4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, sum = 0;
    while (cin >> x && x != -1)
        sum += x;
    cout << sum << '\n';
    return 0;
}
