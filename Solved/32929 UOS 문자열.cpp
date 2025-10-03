//* https://www.acmicpc.net/problem/32929
//* Bronze 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    cin >> x;

    int r = x % 3;
    if (r == 1)
        cout << "U\n";
    else if (r == 2)
        cout << "O\n";
    else
        cout << "S\n";

    return 0;
}
